#include "thklog.hpp"

THKLog::~THKLog()
{
	logFile.close();
}
