//
// Created by alexandru on 24/10/24.
//

#include "prng.h"

// Define lcg_prng: a function to generate a pseudorandom byte
// Relies on input being valid
unsigned char lcg_prng(const char *input_seed) {
  //return (((long long)(25214903917 * input_seed[0] + 11) % 281474976710656) >>
  //        40);

  long long prod = 25214903917 * input_seed[0] + 11;
  prod %= 281474976710656;
  //prod >>= 40;
  return (unsigned char)prod;
}

// Function to generate a pseudorandom byte
// Relies on input being valid
unsigned char *sub_prng(const char *input_seed) {
  unsigned char *nKey;
  nKey = (unsigned char *)malloc(55);
  memcpy(nKey, (input_seed + 1), 54);

  *(nKey + 54) = input_seed[32] - input_seed[1];
  return nKey;
}