//--------------------------------------------------------------
//
// Date and time conversion common fields for ut_date
//
//	GNU GPLv3 licence	GXT utilities by Andrew Bennington 2015 [www.benningtons.net]
//
//--------------------------------------------------------------

#include	<time.h>

#define UT_DATE_S0		8			// size of yyyymmdd

void	ut_date_now(void);			// Get current date & time

int		gxt_iDate[2];				// integer dates in yyyymmdd format
int		gxt_iTime[2];				// integer times in hhmmss format
char	gxt_sDate[UT_DATE_S0+1];	// date in ddmmyyy string format + a null terminator

time_t	gxt_iSecs;					// secs since 1970 - standard UNIX format
