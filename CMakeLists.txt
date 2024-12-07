cmake_minimum_required(VERSION 3.10)
project(mephisto)

set(CMAKE_CXX_STANDARD 17)

# Define source and include directories
include_directories(include)

# Collect all source files for the shared library
file(GLOB_RECURSE RISC_SRC_FILES
        src/risc/instructions/*.cpp
        src/risc/memory/*.cpp
        src/risc/translator/*.cpp
)

# Remove main.cpp from the shared library sources
list(REMOVE_ITEM RISC_SRC_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp")

# Create the shared library `translator`
add_library(translator SHARED ${RISC_SRC_FILES})

# Set library output directory (dll for Windows)
set_target_properties(translator PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"  # For Windows DLLs
)

# Add the executable, linking it to the shared library
add_executable(Mephisto src/main.cpp)
target_link_libraries(Mephisto translator)

# Handle Windows-specific configurations
if (WIN32)
    # Ensure the .dll file is in the same directory as the executable
    set_target_properties(Mephisto PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
endif()