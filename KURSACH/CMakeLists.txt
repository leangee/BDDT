cmake_minimum_required(VERSION 3.10)
project(RailwaySortingSystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(railway_system
    src/main.cpp
    src/wagon.cpp
    src/sorting_node.cpp
    src/railway_system.cpp
)

if(WIN32)
    target_link_libraries(railway_system)
endif()