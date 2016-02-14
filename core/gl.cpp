#include "gl.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#include <png.h>
#include <boost/gil/gil_all.hpp>
#include <boost/gil/extension/io/png_io.hpp>


GLuint thk::glLoadShader(char const* vertexPath, char const* fragmentPath)
{
	std::cout << "Loading shaders: " << vertexPath << ", " << fragmentPath << std::endl;

	// Create the shaders
	GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	// Read the Vertex Shader code from the file
	std::string vertexShader;
	std::ifstream vertexShaderStream(vertexPath, std::ios::in);
	if (vertexShaderStream.is_open())
	{
		std::string Line = "";
		while (getline(vertexShaderStream, Line))
			vertexShader += "\n" + Line;
		vertexShaderStream.close();
	}
	else
	{
		std::cerr << "Unable to read vertex shader at:" << vertexPath << std::endl;
		return 0;
	}

	GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	// Read the Fragment Shader code from the file
	std::string fragmentShader;
	std::ifstream fragmentShaderStream(fragmentPath, std::ios::in);
	if (fragmentShaderStream.is_open())
	{
		std::string Line = "";
		while (getline(fragmentShaderStream, Line))
			fragmentShader += "\n" + Line;
		fragmentShaderStream.close();
	}
	else
	{
		std::cerr << "Unable to read fragment shader at:" << fragmentPath << std::endl;
		return 0;
	}

	GLint result = GL_FALSE;
	int infoLogLength;

	// Compile Vertex Shader
	char const* temp = vertexShader.c_str();
	glShaderSource(vertexShaderId, 1, &temp, NULL);
	glCompileShader(vertexShaderId);

	// Check Vertex Shader
	glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vertexShaderId, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0)
	{
		std::vector<char> vertexShaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(vertexShaderId, infoLogLength, NULL, &vertexShaderErrorMessage[0]);
		std::cerr << vertexShaderErrorMessage[0] << std::endl;
	}

	// Compile Fragment Shader
	temp = fragmentShader.c_str();
	glShaderSource(fragmentShaderId, 1, &temp, NULL);
	glCompileShader(fragmentShaderId);

	// Check Fragment Shader
	glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fragmentShaderId, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0)
	{
		std::vector<char> fragmentShaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(fragmentShaderId, infoLogLength, NULL, &fragmentShaderErrorMessage[0]);
		std::cerr << fragmentShaderErrorMessage[0] << std::endl;
	}

	// Link the program
	GLuint programId = glCreateProgram();
	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderId);
	glLinkProgram(programId);

	// Check the program
	glGetProgramiv(programId, GL_LINK_STATUS, &result);
	glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0)
	{
		std::vector<char> programErrorMessage(infoLogLength + 1);
		glGetProgramInfoLog(programId, infoLogLength, NULL, &programErrorMessage[0]);
		std::cerr << &programErrorMessage[0] << std::endl;
	}

	return programId;
}

GLuint thk::glLoadBMP(char const* const path)
{
	unsigned char header[54];
	unsigned int dataPointer;
	unsigned int width, height;
	unsigned int imageSize; // = width * height * 3, total numbers of valid float
	unsigned char* data;

	FILE* file; fopen_s(&file, path, "rb");
	if (!file)
	{
		std::cerr << "Unable to read image at:" << path << std::endl;
		return 0;
	}
	if (fread(header, 1, 54, file) != 54)
	{
		std::cerr << "Incorrect BMP file:" << path << std::endl;
		return 0;
	}
	// BMP header always begin with B and M
	if (header[0] != 'B' || header[1] != 'M')
	{
		std::cerr << "Incorrect BMP file:" << path << std::endl;
		return 0;
	}
	// Error check complete

	dataPointer = *(int*)&(header[0x0A]);
	imageSize   = *(int*)&(header[0x22]);
	width       = *(int*)&(header[0x12]);
	height      = *(int*)&(header[0x16]);
	
	// Correct misformated BMP files
	if (imageSize == 0) imageSize = width * height * 3;
	if (dataPointer == 0) dataPointer = 54;

	data = new unsigned char[imageSize];
	fread(data, 1, imageSize, file);

	fclose(file);
	// File reading complete, file is closed.

	// OpenGL file initialisation

	GLuint texture;
	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	delete[] data; // Data is transfered.

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);

	return texture;
}

GLuint thk::glLoadPNG(char const* const path)
{
	using namespace boost::gil;
	rgba8_view_t view;
	png_read_and_convert_view(path, view);

	unsigned char* data = new unsigned char[view.width() * view.height() *
			num_channels<rgba8_pixel_t>()];

	std::size_t i = 0;
 	for (int x = 0; x < view.width(); ++x)
	{
		auto it = view.col_begin(x);
		for (int y = 0; y < view.height(); ++y)
		{
			data[i] = at_c<0>(it[y]); ++i;
			data[i] = at_c<1>(it[y]); ++i;
			data[i] = at_c<2>(it[y]); ++i;
			data[i] = at_c<3>(it[y]); ++i;
		}
 	}
	// OpenGL file initialisation

	GLuint texture;
	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)view.width(), (GLsizei)view.height(),
				 0, GL_BGRA, GL_UNSIGNED_BYTE, data);

	delete[] data; // Data is transfered.

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);

	return texture;
}


