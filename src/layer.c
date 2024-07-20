#include <stdio.h>

#include "layer.h"

#include "perceptron.h"

struct layer * make_layer (unsigned int nb_neurons)
{
    if (nb_neurons == 0) return NULL; 

    struct layer *layer = malloc(sizeof(struct layer));
    
    layer->nb_neurons = nb_neurons;
    layer->neurons = malloc(layer->nb_neurons * sizeof(struct perceptron));
    
    return layer;
}


void free_layer (struct layer *layer)
{
    if (layer == NULL) return;

    free_perceptron(layer->neurons);
    free(layer);
}
