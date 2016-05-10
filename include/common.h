// Author:			William Joseph Oney, Jr.
// Contact:			giantsoftllc@gmail.com
// Organization:
// Date:			2016

/*! \file common.h
    \brief	Defines mins, maxes, ranges and sizes common to all programs in this
    		collection
*/

#ifndef CH30053925_COMMON_H
#define CH30053925_COMMON_H

#define _FILE_OFFSET_BITS 64

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <fcntl.h>

#define MIN_N  0
#define MAX_N  1000000

#define MIN_K  0
#define MAX_K  100000

#define MIN_B  0
#define MAX_B  1

#define MIN_S -100000
#define MAX_S  100000

#define MIN_DIMENSIONS		2
#define MAX_DIMENSIONS		8
#define RNG_DIMENSIONS		6
#define RNG_DIMENSIONS_P1	7

#define SZ_INT4		4
#define SZ_ULONG	8
#define SZ_DBL		8

#endif