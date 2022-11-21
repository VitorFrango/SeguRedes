cmake_minimum_required(VERSION 3.23)
project(SeguRedes C)

set(CMAKE_C_STANDARD 99)

add_executable(SeguRedes main.c algoritmoRSA.c RSA.c)
add_executable(SeguRedes_desencriptacesar  desencriptacesar.c)
add_executable(SeguRedes_encriptacesar  encriptacesar.c)
add_executable(SeguRedes_algoritmoRSA  algoritmoRSA.c)
add_executable(SeguRedes_RSA  RSA.c)

