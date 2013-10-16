// Log.cpp

//
// Written by Kenneth Ang
//

//include if using precompiled headers
//#include "stdafx.h"

#include "Log.h"

#ifndef NLOG

#define MAX_BUFFER_SIZE 100

std::string Log::getCurrentTime(void)
{
	time_t secondsNow = time(NULL);
	struct tm* timeNow = localtime(&secondsNow);
	char formattedTime[MAX_BUFFER_SIZE];
	size_t numCharsInArr = strftime(formattedTime, MAX_BUFFER_SIZE, "%X", timeNow);

	assert(numCharsInArr > 0);
	return (std::string)formattedTime;
}

void logging(std::string message, LogLevel level)
{
	static std::string logFileName;
	static std::ofstream logFile;
	static bool initialised = false;

	if(!initialised)
	{
		time_t secondsNow = time(NULL);
		struct tm* timeNow = localtime(&secondsNow);
		logFileName += "Log ";
		logFileName += PROGRAM_NAME;
		logFileName += " ";
		logFileName += std::to_string(timeNow->tm_year + 1900);
		logFileName += std::to_string(timeNow->tm_mon + 1);
		logFileName += std::to_string(timeNow->tm_mday);
		logFileName += std::to_string(timeNow->tm_hour);
		logFileName += std::to_string(timeNow->tm_min);
		logFileName += std::to_string(timeNow->tm_sec);
		logFileName += ".txt";

		logFile.open(logFileName, std::ios::out);

		assert(logFile.is_open());

		//logging started
		logFile<<"Logging has started for levels: ";
	#ifndef NLOG_DEBUG
		logFile<<" DEBUG";
	#endif
	#ifndef NLOG_INFO
		logFile<<" INFO";
	#endif
	#ifndef NLOG_WARNING
		logFile<<" WARNING";
	#endif
	#ifndef NLOG_ERROR
		logFile<<" ERROR";
	#endif
		logFile<<std::endl;
		initialised = true;
	}

	// Logs messages as YYYY-MM-DD HH:MM:SS <LogLevel>: <message>
	switch(level)
	{
#ifndef NLOG_DEBUG
		case LogLevel::Debug:
		{
			logFile<<getCurrentTime()<<" ";
			logFile<<"Debug: "<<message<<std::endl;
			break;
		}
#endif
#ifndef NLOG_INFO
		case LogLevel::Info:
		{
			logFile<<getCurrentTime()<<" ";
			logFile<<"Info: "<<message<<std::endl;
			break;
		}
#endif
#ifndef NLOG_WARNING
		case LogLevel::Warning:
		{
			logFile<<getCurrentTime()<<" ";
			logFile<<"Warning: "<<message<<std::endl;
			break;
		}
#endif
#ifndef NLOG_ERROR
		case LogLevel::Error:
		{
			logFile<<getCurrentTime()<<" ";
			logFile<<"Error: "<<message<<std::endl;
			break;
		}
#endif
	}
}

#endif