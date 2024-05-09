cmake_minimum_required(VERSION 3.16)

project(Binarytree)

set(CMAKE_CXX_STANDARD 17)

add_executable(binarytree_traversal PreorderInorderPostorder.cpp)

add_executable(levelorder LevelOrder.cpp)


