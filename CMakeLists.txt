cmake_minimum_required(VERSION 3.29)
project(enigma C)

set(CMAKE_C_STANDARD 11)

add_executable(enigma main.c
        utils/prng.c
        utils/prng.h
        utils/base64.c
        utils/base64.h
        utils/includes.h
        utils/crypto.c
        utils/crypto.h
        utils/interface.c
        utils/interface.h)

add_executable(cypherbreak decrypt.c
        utils/prng.c
        utils/prng.h
        utils/base64.c
        utils/base64.h
        utils/includes.h
        utils/crypto.c
        utils/crypto.h
        utils/interface.c
        utils/interface.h)