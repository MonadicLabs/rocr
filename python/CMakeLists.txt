
include( ${ROCR_SOURCE_DIR}/extdeps/pybind11/CMakeLists.txt )

message("popo ${ROCR_SOURCE_DIR}/extdeps/pybind11")

include_directories( ${ROCR_SOURCE_DIR}/lib/include )

# Create the binding library
file ( GLOB_RECURSE PYROCR_CPP ${ROCR_SOURCE_DIR}/lib/src/*.cc )
pybind11_add_module(pyrocr "${PYROCR_CPP};module.cc" )
pybind11_enable_warnings(pyrocr)
