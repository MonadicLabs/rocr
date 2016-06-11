cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(LIBROCR CXX)

# Set custom cmake scripts directory
# set( CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${LIBCCCC_SOURCE_DIR}/cmake")

# Add Dynamic Library Loader dependency, pthread, uuid (if UNIX-based)
if( ${ROCR_CURRENT_SYSTEM} STREQUAL "LINUX" )
    set( DEPS "${DEPS};dl" )
    set( DEPS "${DEPS};pthread" )
endif()

# Set include directories
include_directories( ${LIBROCR_SOURCE_DIR}/include )

# Make headers appear in QtCreator
FILE(GLOB_RECURSE HeaderFiles "include/*.h")
add_custom_target(headers SOURCES ${HeaderFiles})

file ( GLOB_RECURSE CORE_CPP ./src/*.cc )
set( LIBROCR_CPP ${CORE_CPP} )
if( ${ROCR_CURRENT_SYSTEM} STREQUAL "WINDOWS" )
  add_library( rocr ${LIBROCR_CPP} )
else()
  add_library( rocr SHARED ${LIBROCR_CPP} )
endif()

# Link libraries
target_link_libraries( rocr ${DEPS} )
