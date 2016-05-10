#include "shell_util.h"

struct timespec su_beep_sleep = { 0, 130000000L };

void shell_beep( unsigned char beeps ) {

	while( beeps-- ) {
		
		printf( "\a"); fflush( stdout );
		
		if( beeps ) nanosleep( &su_beep_sleep, NULL );

	}

}