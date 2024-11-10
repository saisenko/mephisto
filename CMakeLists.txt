cmake_minimum_required(VERSION 3.10)
project(mephisto)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

# Collect all source files for the executable, excluding main.cpp for the library
file(GLOB_RECURSE SRC_FILES src/*.cpp)
list(REMOVE_ITEM SRC_FILES ${CMAKE_SOURCE_DIR}/src/main.cpp)

# Create the shared library `translator` from specific files
add_library(translator SHARED ${SRC_FILES})

# Set library output directory
set_target_properties(translator PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib"
)

# Add the executable with main.cpp and link it to the `translator` library
add_executable(Mephisto src/main.cpp)
target_link_libraries(Mephisto translator)
