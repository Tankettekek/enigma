//
// Created by alexandru on 27/10/24.
//

#include "interface.h"

ACTION chooseAction() {
  int action;

  printf("\033[2J\033[H");

  printf("Choose action:\n");
  printf("1. \033[32mEncrypt \033[0m   \n");
  printf("2. \033[32mDecrypt \033[0m  \n");
  printf("Your choice: \033[32m");
  int res = scanf("%d", &action);
  printf("\033[0m");
  if (res != 1) {
    printf("\033[31mInvalid input\033[0m\n");
    exit(EXIT_FAILURE);
  }

  return (ACTION)(action-1);
}

ENCRYPTION chooseEncryption() {
  int encryption;

  printf("\033[2J\033[H");
  printf("Choose action:\n");
  printf("1. \033[32mLibc rand\033[0m\n");
  printf("2. \033[32mlcg_prng \033[0m\n");
  printf("3. \033[32msub_prng \033[0m\n");
  printf("Your choice:\033[32m ");
  int res = scanf("%d", &encryption);
  printf("\033[0m");
 if (res != 1) {
    printf("Invalid input\n");
    exit(EXIT_FAILURE);
  }
  return (ENCRYPTION)(encryption-1);
}

char *getInputString() {
  char *string = (char *)malloc(500);
  printf("\033[2J\033[H");

  printf("Input : \033[32m");

  int res = scanf("\n\n%499[^\n]", string);
  printf("\033[0m");

  if (res != 1) {
    printf("Invalid input\n");
    exit(EXIT_FAILURE);
  }
  return string;
}

char *getInputKey() {
  char *key = (char *)malloc(57);
  printf("\033[2J\033[H");

  printf("Input the key: \033[32m");
  int res = scanf("%55s", key);
  printf("\033[0m");

  if (res != 1) {
    printf("Invalid input\n");
    exit(EXIT_FAILURE);
  }

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