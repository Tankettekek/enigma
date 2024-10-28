#include "utils/includes.h"

int likelihood(char *string) {
  int countSpecial = 0;
  int countNormal = 0;

  int i = 0;
  while (string[i] != '\0') {
    if ( (string[i] > 64 && string[i] < 91) || (string[i] > 96 && string[i] < 123) || string[i] == 32) {
      countNormal++;
    } else {
      countSpecial++;
    }
    i++;
  }

  if (countSpecial * 4 > countNormal) {
    return 0;
  } else {
    return 1;
  }
}

int main(void){
  printf("This program will only be able to decrypt cyphers with using a 1 byte key\n");
  printf("Please input the cypher you want to decrypt: ");
  char *cypher = (char *)malloc(500);
  int result = scanf("%499[^\n]", cypher);
  if (result != 1) {
    exit(EXIT_FAILURE);
  }


  int decoded = b64_decoded_size(cypher);
  unsigned char *cypher_decoded = (unsigned char *)malloc(decoded);\
  b64_decode(cypher, cypher_decoded, decoded, strlen(cypher));

  for (int i = 0; i < 256; i++){
    int flag = 0;
    char *decrypted = (char *)malloc(strlen(cypher));
    for (int j = 0; j < strlen(cypher_decoded); j++){
      decrypted[j] = cypher_decoded[j] ^ i;
      if (decrypted[j] < 32 || decrypted[j] > 126){
        flag = 1;
        break;
      }
    }
    if (flag == 0){
      printf("Key %d: %s%s\033[0m\n", i, likelihood(decrypted)? "\033[0;32m": "\033[0;31m", decrypted);
    }
    free(decrypted);
  }
  free(cypher);
  return 0;
}