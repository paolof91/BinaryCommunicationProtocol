cmake_minimum_required(VERSION 3.5)
project( Dispatcher )

find_package(PythonLibs 3.10 REQUIRED)
find_package(Boost COMPONENTS python310 REQUIRED)

include_directories( include 
                     ${Boost_INCLUDE_DIRS}
                     ${PYTHON_INCLUDE_DIRS}
                    )


###
# Robot executable
###
set(SOURCES src/DispatcherCallbackProvider.cpp )
add_executable( Robot src/main.cpp ${SOURCES})


###
# Python bindings
###
add_library(Messages MODULE src/MessagesPythonWrapper.cpp)
target_link_libraries(Messages ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
target_include_directories(Messages PRIVATE ${PYTHON_INCLUDE_DIRS})

# Copy the __init__.py file
configure_file(src/__init__.py ${CMAKE_CURRENT_BINARY_DIR}/__init__.py  COPYONLY)

# Suppress prefix "lib" because Python does not allow this prefix
set_target_properties(Messages PROPERTIES PREFIX "")


            