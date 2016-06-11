cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(ROCR)

option(BUILD_TEST "Build Unit tests" OFF)
option(BUILD_EXAMPLES "Build Examples" ON)
option(BUILD_PYTHON_MODULE "Build Python module" OFF)

option(WITH_PROF "Enable profiling and coverage report analysis" OFF)

# Handle platform specifics
if ( "${CMAKE_SYSTEM_NAME}" MATCHES "Windows" )
        SET( ROCR_CURRENT_SYSTEM "WINDOWS" )
    ADD_DEFINITIONS( -D__WINDOWS__ )
elseif( "${CMAKE_SYSTEM_NAME}" MATCHES "Linux" )
        SET( ROCR_CURRENT_SYSTEM "LINUX" )
    ADD_DEFINITIONS( -D__LINUX__ )
elseif( "${CMAKE_SYSTEM_NAME}" MATCHES "Darwin" )
        SET( ROCR_CURRENT_SYSTEM "MACOSX" )
    ADD_DEFINITIONS( -D__MACOSX__ )
endif()

## CHECK FOR COMPILER CAPABILITIES
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
  message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()
##

# Library
add_subdirectory(lib)

if( BUILD_TEST )
        add_subdirectory(test)
endif( BUILD_TEST )

#if( BUILD_EXAMPLES )
        add_subdirectory( examples )
#endif( BUILD_EXAMPLES )

if( BUILD_PYTHON_MODULE )
    add_subdirectory( python )
endif( BUILD_PYTHON_MODULE )
