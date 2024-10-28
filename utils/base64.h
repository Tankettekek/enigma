//
// Created by alexandru on 24/10/24.
//

#ifndef BASE64_H
#define BASE64_H

#include "includes.h"

char * b64_encode(const unsigned char *input, size_t input_len);
int b64_decode(const char *input, unsigned char * out, size_t output_len, size_t inLen);
size_t b64_decoded_size(const char *in);

#endif //BASE64_H
