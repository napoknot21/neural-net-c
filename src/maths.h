#ifndef MATHS_h
#define MATHS_h

#include <stdio.h>
#include <math.h>

#define MIN(i, j) ((i) <= (j) ? (i) : (j))
#define MAX(i, j) ((i) >= (j) ? (i) : (j))

/*
 * Common activation functions
 */
double sigmond_function (double z);
double hyperbolic_tangent (double z);
double rectified_linear_unit (double z);

#endif