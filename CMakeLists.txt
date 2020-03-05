cmake_minimum_required(VERSION 3.10)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
set(VCPKG_FOLDER "" CACHE PATH "specify vcpkg.cmake path")
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_FOLDER}/vcpkg.cmake")
endif()

project("bsdiff_tool")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(bsdiff_tool_repository_root ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory("src/")