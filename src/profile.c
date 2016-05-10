// Author:	William Joseph Oney, Jr.
// Org:		Giantsoft, LLC 2016
// Contact:	giantsoftllc@gmail.com

#include "common.h"
#include "test_case.h"

enum { ERROR_OK, ERROR_CWD };

void print_usage() {

	printf( "\nUsage: profile COMMAND\n\n" );
	
}

void help() {

	print_usage();

	printf( "COMMAND can be one of the following:\n\n");
	printf( "\tgentests - generate tests" );
	printf( "\n\n" );

}

int gentests( int *argc, char *argv ) {

	char cwd[ 1024 ];
	
	if( getcwd( cwd, 1024 ) != cwd) return ERROR_CWD;

	TEST_CASE tcase;

	printf( "== Generating tests...\n" );
	
	printf( "\tcwd: %s\n", cwd );

	tcase_randomize( &tcase );
	tcase_print( &tcase );
	tcase_gen_files( &tcase, cwd );

	printf( "\n" );

	printf( "\n== Tests generated.\n\n" );

	return 0;

}

void *get_cmd_func( int *argc, char *argv[] ) {

	int err;

	printf("\n");

	if( *argc < 2 ) {
		
		print_usage( 1 );
		printf( "Use 'profile help' -- for more information\n" );

		return 0;

	} else {

		char * cmd = argv[ 1 ];

		if( !strcmp( cmd, "help" ) ) help();
		
		else if( !strcmp( cmd, "gentests" ) ) return &gentests;
		
		else print_usage();

		return 0;

	}

}

int main( int argc, char *argv[] ) {
	
	int (*cmd_func)( int*, char** ) = get_cmd_func( &argc, argv );

	if( cmd_func ) return cmd_func( &argc, argv );

}