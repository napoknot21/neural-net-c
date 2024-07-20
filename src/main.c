#include <stdio.h>

#include "maths.h"
#include "perceptron.h"

int main (int argc, char **argv) {

    // Number of inputs for the perceptron
    unsigned int nb_inputs = 3;

    // Create the perceptron
    struct perceptron *my_perceptron = make_perceptron(nb_inputs);

    if (!my_perceptron) {
        fprintf(stderr, "Failed to create perceptron\n");
        return 1;
    }

    // Initialize inputs and weights
    double inputs[] = {1.0, 2.0, 3.0};
    double weights[] = {0.1, 0.2, 0.3};

    for (int i = 0; i < nb_inputs; i++) {
        my_perceptron->inputs[i] = inputs[i];
        my_perceptron->weights[i] = weights[i];
    }

    // Compute the output
    compute_output(my_perceptron);

    // Print the output
    printf("Perceptron output: %f\n", my_perceptron->output);

    // Free the allocated memory
    free_perceptron(my_perceptron);

    return 0;

}