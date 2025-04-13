cmake_minimum_required(VERSION 3.10)
project(linked_list_ds)

set(CMAKE_CXX_STANDARD 17)

# Include header files directory
include_directories(include)

# Add executable target
add_executable(linked_list_ds
        src/main.cpp
        src/LinkedList.cpp
)
