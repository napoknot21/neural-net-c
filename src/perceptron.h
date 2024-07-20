#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <stdio.h>

#define DEFAULT_BIAS_VALUE 1.0
#define DEFAULT_OUTPUT_VALUE 0.0

struct perceptron
{
    unsigned int nb_inputs;
    double bias;
    double output;

    double *inputs;
    double *weights;
};

struct perceptron * make_perceptron (unsigned int nb_inputs);

void compute_output (struct perceptron *perceptron);

void free_perceptron (struct perceptron *perceptron);


#endif