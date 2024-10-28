//
// Created by alexandru on 24/10/24.
//

#ifndef PRNG_H
#define PRNG_H

#include "includes.h"

// Random byte generators
// Both take a pointer to a key and generate a byte
unsigned char lcg_prng(const char *input_seed);
unsigned char *sub_prng(const char *input_seed);

#endif  // PRNG_H
