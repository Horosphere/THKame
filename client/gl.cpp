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

	glDetachShader(programId, fragmentShaderId);
	glDetachShader(programId, vertexShaderId);
	glDeleteShader(fragmentShaderId);
	glDeleteShader(vertexShaderId);

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
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);

	return texture;
}

GLuint thk::glLoadPNG(char const* const path)
{
	using namespace boost::gil;
	rgba8_image_t image;
	png_read_and_convert_image(path, image);
	auto& view = image._view;
	unsigned char* data = new unsigned char[view.width() * view.height() *
		num_channels<rgba8_pixel_t>()];

	std::size_t i = 0;
 	for (int x = 0; x < view.height(); ++x)
	{
		auto it = view.row_begin(x);
		for (int y = 0; y < view.width(); ++y)
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


thk::Font::Font(const char* fontFile, int fontSize): fontSize(fontSize),xStart(0),yStart(0)
{
	memset(characters, 0, sizeof(characters));
	FT_Init_FreeType(&library);
	assert(library != 0);

	FT_New_Face(library, fontFile, 0, &face);
	FT_Set_Char_Size(face, fontSize << 6, fontSize << 6, 72, 72);
	assert(face != 0);


	glGenTextures(1, &textureId);
	/**
	*   使用这个纹理id,或者叫绑定(关联)
	*/
	glBindTexture(GL_TEXTURE_2D, textureId);
	/**
	*   指定纹理的放大,缩小滤波，使用线性方式，即当图片放大的时候插值方式
	*/
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);



	glTexImage2D(
		GL_TEXTURE_2D,      //! 指定是二维图片
		0,                  //! 指定为第一级别，纹理可以做mipmap,即lod,离近的就采用级别大的 远则使用较小的纹理
		GL_ALPHA,           //! 纹理的使用的存储格式
		1024,
		1024,
		0,                  //! 是否的边
		GL_ALPHA,           //! 数据的格式 bmp中 windows,操作系统中存储的数据是bgr格式
		GL_UNSIGNED_BYTE,   //! 数据是8bit数据
		0
		);
}

thk::Font::Character* thk::Font::getCharacter(wchar_t ch)
{
	if (characters[ch].x0 == 0 &&
		characters[ch].x0 == 0 &&
		characters[ch].x1 == 0 &&
		characters[ch].y1 == 0)
	{
		// 说明字符还没有绘制到纹理上，则进行绘制
		if (xStart + fontSize > 1024)
		{
			xStart = 0; // 写满一行,从新开始
			yStart += fontSize; // y开始位置要增加
		}

		FT_Load_Glyph(face, FT_Get_Char_Index(face, ch), FT_LOAD_DEFAULT);
		FT_Glyph glyph;
		FT_Get_Glyph(face->glyph, &glyph);

		FT_Glyph_To_Bitmap(&glyph, ft_render_mode_normal, 0, 1);
		FT_BitmapGlyph bitmap_glyph = (FT_BitmapGlyph)glyph;
		FT_Bitmap& bitmap = bitmap_glyph->bitmap;
		// 如果没有数据，则不写，直接过去
		if (bitmap.width == 0 || bitmap.rows == 0)
		{
			xStart += fontSize / 2;

			characters[ch].x0 = xStart;
			characters[ch].y0 = yStart;
			characters[ch].x1 = xStart + bitmap.width;
			characters[ch].y1 = yStart + bitmap.rows;
			characters[ch].offsetY = 0;
			characters[ch].offsetX = 0;
		}
		else
		{
			glBindTexture(GL_TEXTURE_2D, textureId);

			characters[ch].x0 = xStart;
			characters[ch].y0 = yStart;
			characters[ch].x1 = xStart + bitmap.width;
			characters[ch].y1 = yStart + bitmap.rows;

			characters[ch].offsetY = bitmap_glyph->top;
			characters[ch].offsetX = bitmap_glyph->left;

			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexSubImage2D(
				GL_TEXTURE_2D,
				0,
				xStart,
				yStart,
				bitmap.width,
				bitmap.rows,
				GL_ALPHA,
				GL_UNSIGNED_BYTE,
				bitmap.buffer
				);
			xStart += bitmap.width + 1;
		}
	}
	return  &characters[ch];
}

void thk::Font::drawText(float x, float y, const wchar_t* text)
{
	typedef float TextVertex[5];
	TextVertex  vert[1024];

	float       texWidth = 1024;
	float       texHeight = 1024;
	float       xStart = x;
	float       yStart = y + 16;
	float       zStart = -1;
	unsigned    index = 0;
	unsigned    nSize = wcslen(text);
	float       fHeight = 0;


	for (unsigned i = 0; i < nSize; ++i)
	{
		Character*  ch = getCharacter(text[i]);

		int         h = ch->y1 - ch->y0;
		int         w = ch->x1 - ch->x0;
		float       offset = (float(h) - float(ch->offsetY));
		float       offsetX = float(ch->offsetX);

		// 第一个点
		vert[index + 0][0] = xStart;
		vert[index + 0][1] = yStart - h + offset;
		vert[index + 0][2] = zStart;
		vert[index + 0][3] = ch->x0 / texWidth;
		vert[index + 0][4] = ch->y0 / texHeight;
		// 第二个点
		vert[index + 1][0] = xStart + w;
		vert[index + 1][1] = yStart - h + offset;
		vert[index + 1][2] = zStart;
		vert[index + 1][3] = ch->x1 / texWidth;
		vert[index + 1][4] = ch->y0 / texHeight;
		// 第三个点
		vert[index + 2][0] = xStart + w;
		vert[index + 2][1] = yStart + offset;
		vert[index + 2][2] = zStart;
		vert[index + 2][3] = ch->x1 / texWidth;
		vert[index + 2][4] = ch->y1 / texHeight;
		// 第四个点
		vert[index + 3][0] = xStart;
		vert[index + 3][1] = yStart + offset;
		vert[index + 3][2] = zStart;
		vert[index + 3][3] = ch->x0 / texWidth;
		vert[index + 3][4] = ch->y1 / texHeight;

		index += 4;
		xStart += w + (ch->offsetX);
	}
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);


	glVertexPointer(3, GL_FLOAT, sizeof(TextVertex), vert);
	glTexCoordPointer(2, GL_FLOAT, sizeof(TextVertex), &vert[0][3]);
	glDrawArrays(GL_QUADS, 0, index);
}