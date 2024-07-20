#ifndef LAYER_H
#define LAYER_H

#include <stdio.h>

#include "perceptron.h"

struct layer {
   
    unsigned int nb_neurons;
    struct percetron *neurons;

};

struct layer * make_layer (unsigned int nb_neurons);


#endif
