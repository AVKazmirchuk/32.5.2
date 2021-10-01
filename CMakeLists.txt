cmake_minimum_required(VERSION 3.17)
project(Project VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

set(OPERATION_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)

target_link_libraries(Project PRIVATE nlohmann_json::nlohmann_json)