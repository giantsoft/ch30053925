// Author:			William Joseph Oney, Jr.
// Contact:			giantsoftllc@gmail.com
// Organization:
// Date:			2016

/*! \file test_case.h
    \brief A library for generating random tests.

    Consuming lib can declare and reuse one or more TEST_CASE variables in order
    to randomly generate input files.
*/

/*! \fn void tcase_randomize( TEST_CASE *test_case )
    \brief Opens a file descriptor.
    \param test_case Pointer to the test_case to be randomized.
*/

#ifndef CH30053925_TEST_CASE_H
#define CH30053925_TEST_CASE_H

typedef struct {

	unsigned int seed;

	int dimensions;
	int n_vars;
	unsigned long n_tups;
	
	int bpt;
	unsigned long sz_data;

	double avg;

} TEST_CASE;

void tcase_randomize( TEST_CASE * );

void tcase_print_hdr();

void tcase_print( TEST_CASE *, char );

void tcase_gen_files( TEST_CASE *, const char * );

#endif