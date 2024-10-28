cmake_minimum_required(VERSION 3.29)
project(enigma C)
include(CTest)

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

add_executable(prng_test tests/prng_test.c
        utils/prng.c
        utils/prng.h
)

add_test(NAME prng_test COMMAND $<TARGET_FILE:prng_test>)