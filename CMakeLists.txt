cmake_minimum_required(VERSION 3.25)
project(DZ3_Algorithm_ex1)

set(CMAKE_CXX_STANDARD 17)

add_executable(DZ3_Algorithm_ex1 main.cpp)

add_subdirectory(ArcGraph)
add_subdirectory(ListGraph)
add_subdirectory(MatrixGraph)
add_subdirectory(SetGraph)
add_subdirectory(IGraph)

target_link_libraries(DZ3_Algorithm_ex1 INTERFACE IGraph)

target_link_libraries(DZ3_Algorithm_ex1 PUBLIC ArcGraph ListGraph MatrixGraph SetGraph)
