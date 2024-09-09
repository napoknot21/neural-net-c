#ifndef LAYER_H
#define LAYER_H

#include <stdio.h>

#include "perceptron.h"

struct layer 
{   
    unsigned int nb_neurons;

    struct percetron *neurons;
    double *outputs;
};

struct layer * make_layer (unsigned int nb_neurons, unsigned int nb_inputs);

void compute_layer_output(struct layer *layer, double *inputs);

void free_layer(struct layer *layer);


#endif
