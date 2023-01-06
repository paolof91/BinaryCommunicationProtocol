#pragma once

#include <boost/python.hpp>

#include "Messages.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(Messages)
{
    class_<EnableFlashMessage>("EnableFlashMessage")
        .def("serialize", &EnableFlashMessage::serialize)
        .def("deserialize", &EnableFlashMessage::deserialize)
    ;
}