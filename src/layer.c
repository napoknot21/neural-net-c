#include <stdio.h>

#include "layer.h"

#include "perceptron.h"

struct layer * make_layer (unsigned int nb_neurons, unsigned int inputs)
{
    struct layer *layer = malloc(sizeof(struct layer));
    if (!layer) return NULL;

    layer->nb_neurons = nb_neurons;
    layer->neurons = malloc(nb_neurons * sizeof(struct perceptron));
    layer->outputs = malloc(nb_neurons * sizeof(double));
    
    if (!layer->neurons || !layer->outputs) 
    {
        free(layer->neurons);
        free(layer->outputs);
        free(layer);
        return NULL;
    }

    for (unsigned int i = 0; i < nb_neurons; i++)
    {
        layer->neurons[i] = *make_perceptron(nb_inputs);
    }

    return layer;
}


void free_layer (struct layer *layer)
{
    if (layer)
    {
        for (unsigned int i = 0; i < layer->nb_neurons; i++)
        {
            free_perceptron(&layer->neurons[i]);
        }

        free(layer->neurons);
        free(layer->outputs);
        free(layer);
    }
}
