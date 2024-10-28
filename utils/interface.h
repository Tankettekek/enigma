//
// Created by alexandru on 27/10/24.
//

#ifndef DISPLAY_H
#define DISPLAY_H

#include "includes.h"

typedef enum ACTION {
    ENCRYPT,
    DECRYPT,
} ACTION;

typedef enum ENCRYPTION {
    LIBC_RAND,
    LCG_PRNG,
    SUB_PRNG
} ENCRYPTION;

typedef struct Operation {
    ACTION action;
    ENCRYPTION encryption;
    char *string;
    char *key;
} Operation;

// ACTION chooseAction();
// ENCRYPTION chooseEncryption();
// char *getInputString();
// char *getInputKey();

Operation *getOperation();

#endif //DISPLAY_H
