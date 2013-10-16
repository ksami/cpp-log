cpp-log
=======

Logging in C++
  
  
//////////////////////////////////////////////////////
// Purpose: Implements logging with severity levels //
//////////////////////////////////////////////////////
  
//  
// To use, add into your source file:	#include "Log.h"  
// change line 46 below:				#define PROGRAM_NAME "yourProgramName"  
// call this function to log:			logging(std::string message, LogLevel level);  
//  
// example:  
// #include "Log.h"  
// #define PROGRAM_NAME "MyOrganiser"  
// logging("This is a log message", LogLevel::Info);  
//  
  
//  
// Creates a file called Log PROGRAM_NAME YYYYMMDDHHMMSS.txt  
// Write logs using the macro function logging(string message, LogLevel level)  
// Logging Severity Levels: DEBUG, INFO, WARNING, ERROR  
// Use #define NLOG before #include "Log.h" to switch off logging  
//  
