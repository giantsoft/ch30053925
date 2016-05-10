// Author:	William Joseph Oney, Jr.
// Org:		Giantsoft, LLC 2016
// Contact:	giantsoftllc@gmail.com

#include "profile.h"

double rand_dbl() {
	
	return ( (double) rand() ) / RAND_MAX;

}

void tcase_calc_size_data( TEST_CASE *tcase ) {

	tcase->sz_data = tcase->n_tups * ( tcase->dimensions * 4 + 8 );

}

void tcase_randomize( TEST_CASE *tcase ) {

	srand( tcase->seed );

	tcase->dimensions = rand() % (RNG_DIMENSIONS_P1) + MIN_DIMENSIONS;
	tcase->bpt = tcase->dimensions * 4 + 8;
	tcase->n_tups = 10;//rand_dbl() * MAX_FILE_SIZE / tcase->bpt;
	tcase->n_vars = tcase->n_tups * tcase->dimensions;
	tcase->avg = 0;
	tcase_calc_size_data( tcase );

}

void tcase_print_hdr() {

	printf(
		"\nTest Cases\n"
		"%10s %10s %10s %15s %15s %15s",
		"seed",
		"dimensions",
		"n_vars",
		"n_tups",
		"avg",
		"sz_data"
	);	

}

void tcase_print( TEST_CASE *tcase, char add_hdr ) {

	if( add_hdr ) tcase_print_hdr();

	printf(
		"\n%10d %10d %10d %15lu %15f %15lu",
		tcase->seed,
		tcase->dimensions,
		tcase->n_vars,
		tcase->n_tups,
		tcase->avg,
		tcase->sz_data
	);

}


void tcase_gen_files( TEST_CASE *tcase, const char *prefix ) {

	char	fn[2048];
	int		flags = O_WRONLY | O_CREAT;
	int		fd;
	size_t	len = strlen(prefix);
	ssize_t	written;

	memcpy( fn, prefix, len );
	memcpy( fn+len, ".md\0", 4 );

	printf( "\n" );
	
	printf( "\nGenerating file: %s\n", fn );	

	fd = open( fn, flags, S_IRWXU);

	if( fd < 0 ) abort();

	int v = getpid();

	written = write( fd, &v, 4);

	if( written < 0 ) {
		printf( "error" );
		abort();
	} else {
		
		printf( "wrote: %lu", written);

	}

	printf( "\nGenerating file: %s.head\n", prefix );
	
	printf( "\nGenerating file: %s.tups\n", prefix );

	//FILE * file = fopen64( *dir, 'w' );

}
