cmake_minimum_required(VERSION 3.23)
project(oppg2)

set(CMAKE_CXX_STANDARD 17)



if(!APPLE)
    set(ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}C:/MinGW/bin/pkg-config.exe")
endif()
INCLUDE(FindPkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(oppg2 main.cpp)
target_link_libraries(gtkmm_example ${GTKMM_LIBRARIES})