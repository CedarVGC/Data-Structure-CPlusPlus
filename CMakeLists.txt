cmake_minimum_required(VERSION 3.1)
project(Data_Structure_C__)
set(CMAKE_CXX_STANDARD 14)
add_subdirectory(include)
add_subdirectory(Question)
add_subdirectory(test)
add_executable(Data_Structure_C__ src/main.cpp )
target_link_libraries(Data_Structure_C__ hello)