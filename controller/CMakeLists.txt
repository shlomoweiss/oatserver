# CMakeList.txt : CMake project for controoler lib, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
find_package(oatpp 1.3.0 REQUIRED)

add_library(controller-lib
        mycontroller.cpp
        mycontroller.hpp
        DTOs.hpp
)
target_include_directories(controller-lib PUBLIC "C:/Program Files (x86)/oatpp/include/oatpp-1.3.0/oatpp")
#C:\Program Files (x86)\oatpp\include\oatpp-1.3.0\oatpp\oatpp\core\macro
target_link_directories(controller-lib PUBLIC oatpp::oatpp PUBLIC oatpp::oatpp-test )

set_target_properties(controller-lib  PROPERTIES
        CXX_STANDARD 11
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
)
