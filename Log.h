// Log.h

//
// Written by Kenneth Ang
//

//////////////////////////////////////////////////////
// Purpose: Implements logging with severity levels //
//////////////////////////////////////////////////////

//
// To use, add into your source file:	#include "Log.h"
// change line 46 below:				#define PROGRAM_NAME "yourProgramName"
// call this function to log:			log(std::string message, LogLevel level);
//
// example:
// #include "Log.h"
// #define PROGRAM_NAME "MyOrganiser"
// log("This is a log message", LogLevel::Info);
//

//
// Creates a file called Log PROGRAM_NAME YYYYMMDDHHMMSS.txt
// Write logs using the macro function log(string message, LogLevel level)
// Logging Severity Levels: DEBUG, INFO, WARNING, ERROR
// Use #define NLOG before #include "Log.h" to switch off logging
//

#pragma once

#undef log

#ifdef NLOG
#define log(string, LogLevel) ((void)0)
#else
#define log(string, LogLevel) Log::logging(string, LogLevel)

#include <iostream>
#include <fstream>
#include <ctime>

//to switch off assertions
//#define NDEBUG
#include <assert.h>

enum LogLevel {Debug, Info, Warning, Error};

#define PROGRAM_NAME "DaOrganiser"

// Use to selectively switch off logging messages
//#define NLOG_DEBUG
//#define NLOG_INFO
//#define NLOG_WARNING
//#define NLOG_ERROR

class Log
{
public:
	static void logging(std::string, LogLevel);
	static std::string getCurrentTime(void);
};

#endif