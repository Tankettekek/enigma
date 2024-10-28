//
// Created by alexandru on 27/10/24.
//

#include "interface.h"

ACTION chooseAction() {
  int action;

  printf("\033[2J\033[H");

  printf("Choose action:\n");
  printf("1. Encrypt    \n");
  printf("2. Decrypt    \n");
  printf("Your choice: ");
  scanf("%d", &action);
  return (ACTION)(action-1);
}

ENCRYPTION chooseEncryption() {
  int encryption;

  printf("\033[2J\033[H");
  printf("Choose action:\n");
  printf("1. Libc rand\n");
  printf("2. lcg_prng \n");
  printf("3. sub_prng \n");
  printf("Your choice:");
  scanf("%d", &encryption);
  return (ENCRYPTION)(encryption-1);
}

char *getInputString() {
  char *string = (char *)malloc(500);
  printf("\033[2J\033[H");

  printf("Input : ");

  scanf("\n\n%499[^\n]", string);
  return string;
}

char *getInputKey() {
  char *key = (char *)malloc(57);
  printf("\033[2J\033[H");

  printf("Input the key: ");
  scanf("%55s", key);
  return key;
}

Operation *getOperation() {
  Operation *operation = (Operation *)malloc(sizeof(Operation));
  operation->action = chooseAction();
  operation->encryption = chooseEncryption();
  operation->string = getInputString();
  operation->key = getInputKey();
  return operation;
}