cmake_minimum_required(VERSION 2.8.4)
project(rownanie_kw_tdd)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c tests.c)
add_executable(rownanie_kw_tdd ${SOURCE_FILES})

target_link_libraries(rownanie_kw_tdd m)
