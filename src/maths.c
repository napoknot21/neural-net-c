#include <stdio.h>
#include <math.h>

#include "maths.h"

double sigmond_function (double z)
{
    double den = 1 + exp(-z);
    return 1.0 / den;
}


double hyperbolic_tangent (double z)
{
    double num = exp(z) - exp(-z);
    double den = exp(z) + exp(-z);

    return num / den;
}


double rectified_linear_unit (double z)
{
    return (double)MAX(0.0, z);
}


double sigmond_function_derivative (double z)
{
    double sig = sigmond_function(z);

    return sig * (1.0 - sig);
}


double hyperbolic_tangent_derivative (double z)
{
    double hyp = hyperbolic_tangent(z);

    return 1.0 - hyp*hyp;
}


double rectified_linear_unit_derivative (double z)
{
    return (z > 0.0 ? 1.0 : 0.0);
}