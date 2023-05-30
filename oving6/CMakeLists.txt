cmake_minimum_required(VERSION 3.23)
project(oving6)

set(CMAKE_CXX_STANDARD 17)

set(Boost_INCLUDE_DIR C:/MinGW/include)
set(Boost_LIBRARY_DIR C:/MinGW/lib)
set(BOOST_ROOT C:/MinGW/include/Boost)
link_libraries(ws2_32 wsock32)
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(oving6 a.cpp)
add_executable(ovin b.cpp)