#include <stdio.h>
#include <math.h>

#include "maths.h"

double sigmond_function(double z)
{
    double den = 1 + exp(-z);
    return 1.0 / den;
}


double hyperbolic_tangent(double z)
{
    double num = exp(z) - exp(-z);
    double den = exp(z) + exp(-z);

    return num / den;
}


double rectified_linear_unit(double z)
{
    return (double)MAX(0.0, z);
}
