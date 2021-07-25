cmake_minimum_required(VERSION 3.18)
project(myproject)

# Define project C++ standard.
set(CMAKE_CXX_STANDARD 17)

# Set up GoogleTest.
include(GoogleTest REQUIRED)
enable_testing()

# Set up packages installed from Conan package manager,
# which includes 'gtest' and 'gmock' in this boilerplate.
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# >> For library deliverables
# Subdirectory for header files that are part of the public API.
include_directories(include)

# Subdirectory for executables.
add_subdirectory(apps)

# >> For library deliverables
# Subdirectory for implementation files, test drivers and private headers.
add_subdirectory(src)