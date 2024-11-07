cmake_minimum_required(VERSION 3.10)
project(mephisto)

set(CMAKE_CXX_STANDARD 17)

add_library(translator SHARED
    src/main.cpp
)

set_target_properties(translator PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib"
)
