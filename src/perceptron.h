#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <stdio.h>

#define DEFAULT_BIAS_VALUE 1
#define DEFAULT_OUTPUT_VALUE 0

struct perceptron
{
    int nb_inputs;
    int bias;
    int output;

    int *inputs;
    int *weights;
};

struct perceptron * make_perceptron (int nb_inputs);

void compute_output (struct perceptron *perceptron);

void free_perceptron (struct perceptron *perceptron);


#endif