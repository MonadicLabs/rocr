
INCLUDE_DIRECTORIES( ${LIBROCR_SOURCE_DIR}/include )

find_package( OpenCV REQUIRED )

add_executable( example0 main.cc )

target_link_libraries( example0 rocr ${OpenCV_LIBS} )
