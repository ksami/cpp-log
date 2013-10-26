// Log.cpp

//
// Written by Kenneth Ang
//

//include if using precompiled headers
#include "stdafx.h"

#include "Log.h"

#ifndef NLOG

#define MAX_BUFFER_SIZE 100

std::string Log::getCurrentTime(void)
{
	time_t secondsNow = time(NULL);
	struct tm* timeNow = localtime(&secondsNow);
	char formattedTime[MAX_BUFFER_SIZE];
	size_t numChars = strftime(formattedTime, MAX_BUFFER_SIZE, "%X", timeNow);

	assert(numChars > 0);
	return (std::string)formattedTime;
}

void Log::initialiseLog(std::string& logFileName, std::ofstream& logFile)
{
	time_t secondsNow = time(NULL);
	struct tm* timeNow = localtime(&secondsNow);
	char formattedTime[MAX_BUFFER_SIZE];
	size_t numChars = strftime(formattedTime, MAX_BUFFER_SIZE, "%Y%m%d %H%M%S", timeNow);

	assert(numChars > 0);

	logFileName += "Log ";
	logFileName += PROGRAM_NAME;
	logFileName += " ";
	logFileName += formattedTime;
	logFileName += ".txt";

	logFile.open(logFileName, std::ios::out);

	assert(logFile.is_open());

	//logging started
	logFile<<"Logging has started for levels: ";
#ifndef NLOG_DEBUG
	logFile<<" DEBUG";
#endif
#ifndef NLOG_EVENT
	logFile<<" EVENT";
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
}

void logging(std::string message, LogLevel level)
{
	static std::string logFileName;
	static std::ofstream logFile;
	static bool initialised = false;

	if(!initialised)
	{
		Log::initialiseLog(logFileName, logFile);
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
#ifndef NLOG_EVENT
		case LogLevel::Event:
		{
			logFile<<getCurrentTime()<<" ";
			logFile<<"Event: "<<message<<std::endl;
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