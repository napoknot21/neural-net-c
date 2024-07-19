#include <malloc.h>
#include <unistd.h>

#include "perceptron.h"


/**
 * Creates a new perceptron with the specified number of inputs.
 * @param nb_inputs The number of inputs for the perceptron.
 * @return A pointer to the newly created perceptron. If the number of inputs is less than or equal to zero, the function returns null.
 * @pre The number of inputs must be greater than zero.
 * @post A new perceptron with the specified number of inputs has been created and returned. The inputs and weights arrays have been allocated memory.
 * @warning The weights array is not initialized to any specific value. It is assumed that the caller will initialize the weights array separately.
 */
struct perceptron * make_perceptron (int nb_inputs)
{
    if (nb_inputs <= 0) return NULL;
    
    struct perceptron *perceptron = malloc(sizeof(struct perceptron));

    perceptron->nb_inputs = nb_inputs;
    perceptron->bias = DEFAULT_BIAS_VALUE;
    perceptron->output = DEFAULT_OUTPUT_VALUE;
    
    perceptron->inputs = malloc(nb_inputs * sizeof(int));
    perceptron->weights = malloc(nb_inputs * sizeof(int));

    return perceptron;
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


/**
 * Sets the bias of the perceptron.
 * @param perceptron The perceptron whose bias is to be set.
 * @param bias The new bias value.
 * @pre The perceptron must be created using the make_perceptron function.
 * @post The bias of the perceptron has been updated.
 */
int activation_function (int input_sum)
{
    return input_sum > 0 ? 1 : 0;
}


/**
 * Computes the output of the perceptron based on the given inputs and weights.
 * @param perceptron The perceptron whose output is to be computed.
 * @pre The perceptron must be created using the make_perceptron function.
 * @post The output of the perceptron has been computed using the provided inputs and weights.
 * @warning The function assumes that the weights and inputs arrays have been properly initialized.
 */
void compute_output (struct perceptron *perceptron)
{
    if (!perceptron) return;

    int sum = 0;
    for (int i = 0; i < perceptron->nb_inputs; i++)
    {
        sum += perceptron->inputs[i] * perceptron->weights[i];
    }

    perceptron->output = activation_function(perceptron->bias + sum);
}


int main() {


    return 0;
}
