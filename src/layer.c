#include <stdio.h>

#include "layer.h"


struct layer * make_layer (unsigned int nb_neurons)
{
    struct layer *layer = malloc(sizeof(struct layer));
    
    layer->nb_neurons = nb_neurons;
    layer->neurons = malloc(nb_neurons * sizeof(struct perceptron));
    
    return layer;
}
