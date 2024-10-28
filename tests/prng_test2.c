//
// Created by alexandru on 28/10/24.
//

#include "../utils/prng.h"

int main(void){
  unsigned char lcg_prng_result = lcg_prng("r");
  if (lcg_prng_result != 149){
      printf("\033[31m lcg_prng_result is unexpected: %d\n", lcg_prng_result);
      return 1;
  }
  return 0;
}