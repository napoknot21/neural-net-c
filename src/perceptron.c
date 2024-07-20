#include <malloc.h>
#include <unistd.h>
#include <string.h>

#include "perceptron.h"
#include "maths.h"


struct perceptron * make_perceptron (unsigned int nb_inputs)
{
    if (nb_inputs <= 0) return NULL;
    
    struct perceptron *perceptron = malloc(sizeof(struct perceptron));

    perceptron->nb_inputs = nb_inputs;
    perceptron->bias = DEFAULT_BIAS_VALUE;
    perceptron->output = DEFAULT_OUTPUT_VALUE;
    
    perceptron->inputs = malloc(nb_inputs * sizeof(double));
    perceptron->weights = malloc(nb_inputs * sizeof(double));

    return perceptron;
}


void compute_output (struct perceptron *perceptron)
{
    if (!perceptron) return;

    double sum = 0.0;

    if (perceptron->inputs == NULL || perceptron->weights == NULL)
    {
        write(STDOUT_FILENO, "Error: Perceptron has not been initialized.\n", strlen("Error: Perceptron has not been initialized.\n")); 
        perceptron->output = sigmond_function(perceptron->bias + sum);
        return;
    }

    
    for (int i = 0; i < perceptron->nb_inputs; i++)
    {
        sum += perceptron->inputs[i] * perceptron->weights[i];
    }

    perceptron->output = sigmond_function(perceptron->bias + sum);
}


/**
 * Frees the memory allocated for the given perceptron.
 */
void free_perceptron (struct perceptron *perceptron)
{
    if (perceptron)
    {
        free(perceptron->inputs);
        free(perceptron->weights);

        free(perceptron);
    }
}