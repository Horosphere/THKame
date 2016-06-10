#include "THKLog.hpp"

THKLog::~THKLog()
{
	logFile.close();
}
