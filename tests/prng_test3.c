//
// Created by alexandru on 28/10/24.
//

#include "../utils/prng.h"

int main(void) {
  unsigned char *sub_prng_result = sub_prng("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  if (sub_prng_result[54] != 0){
      printf("\033[31m sub_prng_result is unexpected: %d\n", sub_prng_result[54]);
      return 1;
  }
  return 0;
}