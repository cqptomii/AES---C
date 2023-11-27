cmake_minimum_required(VERSION 3.24)
project(AES C)

set(CMAKE_C_STANDARD 11)

add_executable(AES main.c Subbyte.c Subbyte.h ShiftRows.c ShiftRows.h keySchedule.c keySchedule.h mixColum.c mixColum.h keyGenerate.c keyGenerate.h Route.c Route.h findData.c readTextciphered.c)
