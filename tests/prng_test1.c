//
// Created by alexandru on 28/10/24.
//
#include "../utils/prng.h"

int main(){
  unsigned char lcg_prng_result = lcg_prng("t");
  if (lcg_prng_result != 111){
    printf("\033[31m lcg_prng_result is unexpected: %d\n", lcg_prng_result);
    return 1;
  }

  return 0;
}