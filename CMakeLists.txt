cmake_minimum_required(VERSION 3.10)
project(LiteRender)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/release)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/release)

include_directories(
    ${CMAKE_SOURCE_DIR}/third_party/fmt/include
    ${CMAKE_SOURCE_DIR}/third_party/glfw/include
)

link_libraries(
    ${CMAKE_SOURCE_DIR}/third_party/glfw/lib-mingw-w64/glfw3.dll
)

add_definitions(
    -DFMT_HEADER_ONLY
)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    add_compile_options(-O0 -g)
elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    add_compile_options(-O2 -DNDEBUG)
endif()

add_subdirectory(${CMAKE_SOURCE_DIR}/src/lr/gl45)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/lr/vk10)
add_subdirectory(${CMAKE_SOURCE_DIR}/test)
