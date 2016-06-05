#ifndef THKLOG_HPP
#define THKLOG_HPP

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

// Deprecated, do not use this. It is not thread safe.
template<typename Data> THKLog&
operator<<(THKLog&, Data const&);

// Implementations

inline THKLog::THKLog(std::string const& fileName)
{
	logFile.open(fileName, std::ofstream::out);
}

inline void THKLog::write(std::string const& data)
{
	logFile << data;
}


#endif // !THKLOG_HPP
