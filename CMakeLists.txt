cmake_minimum_required(VERSION 3.10)
project(MyLib VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(keep INTERFACE)

# Add the current directory (.) to the include path for this target
target_include_directories(keep INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

enable_testing()
add_subdirectory(tests)
