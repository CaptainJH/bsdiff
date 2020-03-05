cmake_minimum_required(VERSION 3.10)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  
    set(warnings "/W4 /WX")
    set(ParallelBuild "/MP")
    add_definitions(-DUNICODE -D_UNICODE -DWINDOWS -DNOMINMAX -D_CRT_SECURE_NO_WARNINGS)
    MESSAGE( STATUS "MSVC")
    
    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${ParallelBuild}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ParallelBuild}")
    
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
    
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
    set(PLATFORM_OSX true)  
    add_definitions(-DMACOS)
    
    MESSAGE( STATUS "Xcode")
endif()

find_path(BZIP2_INCLUDE_DIR NAMES bzlib.h)
MESSAGE(STATUS ${BZIP2_INCLUDE_DIR})
include_directories(${BZIP2_INCLUDE_DIR})
find_package(Bzip2 REQUIRED)
find_package(ZLIB REQUIRED)

add_definitions(-DBSDIFF_EXECUTABLE -DBSPATCH_EXECUTABLE)
add_executable(bsdiff_cmd bsdiff.c bsdiff.h)

add_executable(bspatch_cmd bspatch.h bspatch.c)

target_link_libraries(bsdiff_cmd ${ZLIB_LIBRARIES})
target_link_libraries(bsdiff_cmd ${BZIP2_LIBRARIES})

target_link_libraries(bspatch_cmd ${ZLIB_LIBRARIES})
target_link_libraries(bspatch_cmd ${BZIP2_LIBRARIES})