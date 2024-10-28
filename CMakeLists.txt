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

add_executable(prng_test_1 tests/prng_test1.c
        utils/prng.c
        utils/prng.h)

add_executable(prng_test_2 tests/prng_test2.c
        utils/prng.c
        utils/prng.h)

add_executable(prng_test_3 tests/prng_test3.c
        utils/prng.c
        utils/prng.h)

add_test(NAME prng_test_1 COMMAND $<TARGET_FILE:prng_test_1>)
add_test(NAME prng_test_2 COMMAND $<TARGET_FILE:prng_test_2>)
add_test(NAME prng_test_3 COMMAND $<TARGET_FILE:prng_test_3>)