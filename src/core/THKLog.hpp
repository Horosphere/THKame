#ifndef _THKAME_CORE_THKLOG_HPP__
#define _THKAME_CORE_THKLOG_HPP__

#include <iostream>
#include <fstream>
#include <string>

class THKLog final
{
public:
	THKLog(std::string const& fileName);
	~THKLog();

	void write(std::string const&);

private:
	std::ofstream logFile;
};

// Implementations

inline THKLog::THKLog(std::string const& fileName)
{
	logFile.open(fileName, std::ofstream::out);
}

inline void THKLog::write(std::string const& data)
{
	logFile << data;
}


#endif // !_THKAME_CORE_THKLOG_HPP__
