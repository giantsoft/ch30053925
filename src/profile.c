// Author:			William Joseph Oney, Jr.
// Contact:			giantsoftllc@gmail.com
// Organization:
// Date:			2016

#include "profile.h"
#include "test_case.h"

enum { ERR_OK, ERR_NO_CMD, ERR_BAD_CMD, ERR_COUNT };

int print_usage(char short_help ) {

	printf( "Usage: profile COMMAND [OPTIONS]\n\n" );

	printf( "COMMAND can be one of the following:\n\n");
	
	printf( "gencase  - generates test case data\n" );
	printf( "test     - run a test\n" );

	printf( "\n" );

	if( short_help ) printf( "Use 'profile help' -- for more information\n" );

	return ERR_NO_CMD;

}

int print_bad_cmd( char *bad_cmd ) {

	printf( "Bad command: %s\n\n", bad_cmd );
	
	print_usage( 1 );

	return ERR_BAD_CMD;

}

int print_help() {

	print_usage( 0 );

	printf( "COMMAND can be one of the following:\n\n");
	
	printf( "gencase - generates test case data\n" );
	printf( "\n");
	printf( "Usage: profile gencase [-sptdv]\n" );
	printf( "\n");
	
	printf( "\t-s SEED = randomly chosen based on time\n");
	printf( "\t    SEED should be a positive integer less than 2^32.\n" );
	printf( "\tTest cases generated with the same SEED and parameters\n" );
	printf( "\twill generate the same data files." );
	printf( "\n\n" );
	
	printf( "\t-p PREFIX = ./TEST_CASE_0\n");
	printf( "\t    The files PREFIX.md, PREFIX.head, and PREFIX.tups will\n" );
	printf( "\tbe created. WARNING: existing files will be overwritten and\n" );
	printf( "\tnon-existing directory paths will be created.\n");
	printf( "\t    PREFIX.md	- case info with seed and vfactor\n" );
	printf( "\t    PREFIX.head	- binary input1 for the processor\n" );
	printf( "\t    PREFIX.tups	- binary input2 for the processor\n" );
	printf( "\n\n" );

	printf( "\t-t TUPLE_COUNT = random\n");
	printf( "\t    TUPLE_COUNT tubles will be generated. Files up to 2GB\n");
	printf( "\twill be generated, so the maximum TUPLE_COUNT is 50M:\n");
	printf( "\t    0 <= TUPLE_COUNT <= 50000000.\n" );
	printf( "\n\n" );
	
	printf( "\t-d DIMENSIONS = random\n");
	printf( "\t    Generated tuples will have DIMENSIONS dimensions where:\n" );
	printf( "\t    2 <= DIMENSIONS <= 8\n");
	printf( "\n\n" );

	printf( "\t-v VCOUNT = random\n");
	printf( "\t    VCOUNT number of values will be used to generate\n" );
	printf( "\ttuples.  Tuple generation will stop when no more unique\n");
	printf( "\ttuples can be generated either because TUPLE_COUNT tuples\n");
	printf( "\thave been generated or because the next tuple would require\n");
	printf( "\ta value of VCOUNT + 1 in order to be unique.");
	printf( "\n\n" );

	printf( "test - run a test\n" );
	printf( "\n" );
	printf( "\t-p PREFIX = case\n");
	printf( "\t    The files PREFIX.head and PREFIX.body will be created.\n" );
	printf( "\tWARNING: existing files will be overwritten and non-\n" );
	printf( "\texisting directories will be created.\n" );
	printf( "\n\n" );

}

int gencase( int *argc, char *argv[] ) {

	TEST_CASE	tcase;

	tcase.seed = getpid();

	printf( "== Generating tests...\n" );

	tcase_randomize( &tcase );
	tcase_print( &tcase, 1 );
	tcase_gen_files( &tcase, "TEST_CASE_0" );

	printf( "\n" );

	printf( "\n== Tests generated.\n\n" );

	return 0;

}

int proc_cmd( int *argc, char *argv[] ) {

	char * cmd = argv[ 1 ];

	if( !strcmp( cmd, "help" ) ) return print_help();
	
	else if( !strcmp( cmd, "gencase" ) ) return gencase( argc, argv );
	
	else return print_bad_cmd( cmd );

}

int main( int argc, char *argv[] ) {	

	int err;

	printf( "\n" );

	if( argc < 2 ) err = print_usage( 1 ); else err = proc_cmd( &argc, argv );

	printf( "\n" );

	return err;

}