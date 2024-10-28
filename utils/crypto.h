//
// Created by alexandru on 26/10/24.
//

#ifndef ENCRYPT_H
#define ENCRYPT_H

#include "base64.h"
#include "prng.h"

void encryptLibcRand(const char *string, const char *seed, size_t stringSize);
void decryptLibcRand(const char *string, const char *seed, size_t stringSize);
void encryptLcgPrng(const char *string, const char *seed, size_t stringSize);
void decryptLcgPrng(const char *string, const char *seed, size_t stringSize);
void encryptSubPrng(const char *string, const char *seed, size_t stringSize);
void decryptSubPrng(const char *string, const char *seed, size_t stringSize);

#endif  // ENCRYPT_H
