cmake_minimum_required(VERSION 3.13)
project(test_sqlite3)

set(CMAKE_CXX_STANDARD 14)

add_executable(test_sqlite3 main.cpp database.cpp database.h)
target_link_libraries(test_sqlite3 LINK_PUBLIC sqlite3)