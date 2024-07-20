#ifndef NETWORK_H
#define NETWORK_H

#include <stdio.h>

#include "layer.h"

struct network {
    
    unsigned int nb_layers;
    struct layer *layers;

};



#endif
