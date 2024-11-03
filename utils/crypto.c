//
// Created by alexandru on 26/10/24.
//

#include "crypto.h"

void encryptLibcRand(const char *string, const char *seed, size_t stringSize) {
  srand((unsigned int)*seed);
  char key = (char)rand();

  unsigned char *copy;
  copy = (unsigned char *)malloc(stringSize + 1);
  strcpy((char *)copy, string);

  for (int i = 0; i < (int)strlen((const char *)copy); i++) {
    copy[i] = copy[i] ^ key;
  }

  char *b64out;
  b64out = b64_encode(copy, strlen((const char *)copy));

  printf("%s\n", b64out);
  free(copy);
  free(b64out);
}

void decryptLibcRand(const char *string, const char *seed, size_t stringSize) {
  srand((unsigned int)*seed);
  char key = (char)rand();

  unsigned char *b64out;
  b64out = (unsigned char *)malloc(b64_decoded_size(string));
  b64_decode(string, (unsigned char *)b64out, b64_decoded_size(string),
             stringSize);

  for (int i = 0; i < (int)strlen((const char *)b64out); i++) {
    b64out[i] = b64out[i] ^ key;
  }

  printf("%s\n", (const char *)b64out);
  free(b64out);
}

void encryptLcgPrng(const char *string, const char *seed, size_t stringSize) {
  unsigned char key = lcg_prng(seed);

  unsigned char *copy;
  copy = (unsigned char *)malloc(stringSize+1);
  strcpy((char *)copy, string);
  copy[stringSize] = '\0';
  for (int i = 0; i < (int)stringSize; i++) {
    copy[i] = copy[i] ^ key;
  }

  char *b64out;
  b64out = b64_encode(copy, stringSize);

  printf("%s\n", b64out);
  free(copy);
  free(b64out);
}

void decryptLcgPrng(const char *string, const char *seed, size_t stringSize) {
  unsigned char key = lcg_prng(seed);

  unsigned char *b64out;
  size_t decoded = b64_decoded_size(string);
  b64out = (unsigned char *)malloc(decoded);
  b64_decode(string, (unsigned char *)b64out, b64_decoded_size(string),
             stringSize);

  for (int i = 0; i < (int)decoded; i++) {
    b64out[i] = b64out[i] ^ key;
  }


  printf("%s\n", (const char *)b64out);
  free(b64out);
}

void encryptSubPrng(const char *string, const char *seed, size_t stringSize) {
  unsigned char *key, *nKey;
  key = sub_prng(seed);

  unsigned char *copy;
  copy = (unsigned char *)malloc(stringSize+1);
  strcpy((char *)copy, string);

  for (int i = 0; i < (int)strlen((const char *)copy); i++) {
    copy[i] = copy[i] ^ key[54];
    nKey = sub_prng((const char *)key);
    free(key);
    key = nKey;
  }

  char *b64out;
  b64out = b64_encode(copy, strlen((const char *)copy));

  free(copy);
  printf("%s\n", b64out);
  free(b64out);
  free(key);
}

void decryptSubPrng(const char *string, const char *seed, size_t stringSize) {
  unsigned char *key, *nKey;
  key = sub_prng(seed);

  unsigned char *b64out;
  b64out = (unsigned char *)malloc(b64_decoded_size(string));
  b64_decode(string, (unsigned char *)b64out, b64_decoded_size(string),
             stringSize);

  for (int i = 0; i < (int)strlen((const char *)b64out); i++) {
    b64out[i] = b64out[i] ^ key[54];
    nKey = sub_prng((const char *)key);
    free(key);
    key = nKey;
  }

  printf("%s\n", (const char *)b64out);
  free(b64out);
  free(key);
}
