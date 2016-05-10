// Author:	William Joseph Oney, Jr.
// Org:		Giantsoft, LLC 2016
// Contact:	giantsoftllc@gmail.com

#include "common.h"

double rand_score() {
	
	return ( (double) rand() ) / RAND_MAX;

}

void tcase_randomize( TEST_CASE *test_case) {

	test_case->dimensions = rand() % (RANGE_DIMENSIONS_P1) + MIN_DIMENSIONS;
	test_case->n_vars = 0;
	test_case->n_tups = rand();
	test_case->avg = 0;

}

void tcase_print( TEST_CASE *test_case ) {

	printf(
		"\nTest Case( d: %d, n_vars: %d, n_tups: %lu, avg: %f )",
		test_case->dimensions,
		test_case->n_vars,
		test_case->n_tups,
		test_case->avg
	);

}

void tcase_gen_files( TEST_CASE *test_case, const char *dir ) {

	size_t len = strlen( dir );

	printf( "\nProducing test files..2.\n" );

	//FILE * file = fopen64( *dir, 'w' );


}
