// Author:	William Joseph Oney, Jr.
// Org:		Giantsoft, LLC 2016
// Contact:	giantsoftllc@gmail.com

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

#include "main.h"

typedef struct {

	int dimensions;
	int n_vars;
	unsigned long n_tups;
	double avg;

} TEST_CASE;


void tcase_randomize( TEST_CASE *test_case );

void tcase_print( TEST_CASE *test_case );

void tcase_gen_files( TEST_CASE *test_case, const char *dir );

#endif