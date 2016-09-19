//--------------------------------------------------------------
//
// Various C date and time utilities
//
// Based around some common variables and defintions in ut_date.h to avoid passing arguments.
// This was intended to assist sharing functions and data between c and Fortran.
// But I shall probably convert these to traditional (passed arguments and returned value) functions.
// #TODO convert ut_date functions to traditional format
//
//	GNU GPLv3 licence	GXT utilities by Andrew Bennington 2015 [www.benningtons.net]
//--------------------------------------------------------------

#include	<stdlib.h>
#include	<string.h>

#include	<ut_date.h>

void ut_date_now (void)		// Get current date and time in all formats
  {
    struct tm *spTime;

    gxt_iSecs = time(NULL);									// Get seconds since 1970
    spTime = localtime(&gxt_iSecs);							// Convert to a tm structure

    strftime(gxt_sDate, UT_DATE_S0+1, "%Y%m%d", spTime);
    gxt_iDate[0]=atoi(gxt_sDate);							// integer yyyymmdd format

    strftime(gxt_sDate, UT_DATE_S0+1, "%H%M%S", spTime);
    gxt_iTime[0]=atoi(gxt_sDate);							// integer hhmmss format

    strftime(gxt_sDate, UT_DATE_S0+1, "%d%m%Y", spTime);	// string ddmmyyy format

    return;
  }
