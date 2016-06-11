
#include <iostream>

#include <pybind11/pybind11.h>

#include <rocr.h>

using namespace std;
using namespace rocr;

namespace py = pybind11;

PYBIND11_PLUGIN(pyrocr) {
    py::module m("pyrocr", "ReceiptOCR Python module");

    py::class_<ReceiptOCR>(m, "ReceiptOCR")
            .def(py::init<>())
            //.def(py::init<int>())
            //.def(py::init<const ReceiptOCR&>())
            .def("test", &ReceiptOCR::test);

    return m.ptr();
}
