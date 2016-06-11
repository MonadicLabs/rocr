
include( ${ROCR_SOURCE_DIR}/extdeps/pybind11/CMakeLists.txt )

message("popo ${ROCR_SOURCE_DIR}/extdeps/pybind11")

# Create the binding library
pybind11_add_module(pyrocr module.cc)
pybind11_enable_warnings(pyrocr)
