//--------------------------------------------------------------
//
// A range of error handling and debug macros
//
// ut_error(message)				Report an error message in a consistent format (showing the calling program and line number) to stderr
// ut_log(message)					Log a message in a consistent format (showing the calling program and line number) to stderr
// ut_check(condition, message)		If the condition is false then report the message and then jump to an error: label in the calling program
// ut_debug(message)				If in debug mode then (Output a debug message to stderr) else (Ignore all debug messages)
//
//	GNU GPLv3 licence	GXT utilities by Andrew Bennington 2015 [www.benningtons.net]
//
//--------------------------------------------------------------

										//Prevent duplicate inclusions
#ifndef __GXT_UT_ERROR_INCLUDED__
#define __GXT_UT_ERROR_INCLUDED__

#include <stdio.h>
#include <unistd.h>						// for sleep function


//--------------------------------------------------------------
// ut_error(message)		Report an error message in a consistent format (showing the calling program and line number) to stderr
//
//	examples:-							Output:-									#TODO Do something with errno?
//		ut_error("Status=%d", ios);		[ERROR] (src=program.c :36) Status=-1
//		ut_error("Input=%s.", sInput);	[ERROR] (src=program.c :50) Input=rubbish.
//--------------------------------------------------------------

#define ut_error(M, ...) fprintf(stderr, "[ERROR] (src=%s :%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
										// __FILE__ is the program file name, __LINE__ is the program line number
										// ##__VA_ARGS__ means put all additional arguments (the ... bit) here.

//--------------------------------------------------------------
// ut_log(message)					Log a message in a consistent format (showing the calling program and line number) to stderr
//
//	examples:-							Output:-
//		ut_log("Status=%d", ios);		[LOG] (src=program.c :36) Status=0
//		ut_log("New file created");		[LOG] (src=program.c :50) New file created
//--------------------------------------------------------------

#define ut_log(M, ...)   fprintf(stderr, "[LOG] (src=%s :%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)


//--------------------------------------------------------------
// ut_check(condition, message)		If the condition is false then report the message and then jump to an error: label in the calling program
//
//	examples:-													Output:-
//		ut_check(i > 0, "Invalid number %d", i);				[ERROR] (src=program.c :36) Invalid number -1
//		ut_check(open_file(sFn) == 0, "Failed to open");		[ERROR] (src=program.c :25) Failed to open
//--------------------------------------------------------------

#define ut_check(A, M, ...) if(!(A)) { ut_error(M, ##__VA_ARGS__); goto error; }


//--------------------------------------------------------------
// GXT_DEBUG is a shell variable that is defined as:
//		GXT_DEBUG="DEBUG=0"				// to ignore all debug messages
//		GXT_DEBUG="DEBUG=1"				// to display debug messages
//		GXT_DEBUG="DEBUG=n"				// to display debug messages and pause n-1 seconds after each one
//
// GXT_DEBUG is then passed to the gcc compiler with the -D$(GXT_DEBUG) option and this is picked up by the following #if DEBUG pre-compiler checks 
// DEBUG modes can also be forced by a [#define DEBUG=n] within a program
//--------------------------------------------------------------

//--------------------------------------------------------------
// ut_debug(message)				If in debug mode then (Output a debug message to stderr) else (Ignore all debug messages)
//
//	example(in debug mode):-					Output:-
//		ut_debug("i=%d j=%d", i, j);			[DEBUG] (src=program.c :31) i=0 j=10
//--------------------------------------------------------------
#if DEBUG > 0
#define ut_debug(M, ...) {fprintf(stderr, "[DEBUG] (src=%s :%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__); sleep(DEBUG-1);}
#else
#define ut_debug(M, ...)
#endif

#endif

