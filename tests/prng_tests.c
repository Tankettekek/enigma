//
// Created by alexandru on 28/10/24.
//
#include "../utils/prng.h"

int main(){
  unsigned char lcg_prng_result = lcg_prng("t");
  if (lcg_prng_result != 111){
    return 0;
  }

  lcg_prng_result = lcg_prng("r");
  if (lcg_prng_result != 149){
    return 0;
  }

  unsigned char *sub_prng_result = sub_prng("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  if (sub_prng_result[54] != 0){
    return 0;
  }

  return 1;
}