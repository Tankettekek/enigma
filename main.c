#include "utils/includes.h"

int main(void) {
    Operation *operation = getOperation();
    if (operation->action == ENCRYPT) {
        if (operation->encryption == LIBC_RAND) {
        encryptLibcRand(operation->string, operation->key, strlen(operation->string));
        } else if (operation->encryption == LCG_PRNG) {
        encryptLcgPrng(operation->string, operation->key, strlen(operation->string));
        } else if (operation->encryption == SUB_PRNG) {
        encryptSubPrng(operation->string, operation->key, strlen(operation->string));
        }
    } else if (operation->action == DECRYPT) {
        if (operation->encryption == LIBC_RAND) {
        decryptLibcRand(operation->string, operation->key, strlen(operation->string));
        } else if (operation->encryption == LCG_PRNG) {
        decryptLcgPrng(operation->string, operation->key, strlen(operation->string));
        } else if (operation->encryption == SUB_PRNG) {
        decryptSubPrng(operation->string, operation->key, strlen(operation->string));
        }
    }
    free(operation->string);
    free(operation->key);
    free(operation);
    return 0;
}
