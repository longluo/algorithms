cmake_minimum_required(VERSION 3.16)

project(Queue)

set(CMAKE_CXX_STANDARD 17)

add_executable(queue_array Queue_CircularArray.cpp)

add_executable(queue_linkedlist Queue_LinkedList.cpp)

