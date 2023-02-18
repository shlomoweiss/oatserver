# CMakeList.txt : CMake project for oat, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
find_package(oatpp 1.3.0 REQUIRED)

# Add source to this project's executable.
add_executable (oat "oat.cpp" "oat.h")
target_include_directories(oat PUBLIC "C:/Program Files (x86)/oatpp/include/oatpp-1.3.0/oatpp/")
target_link_libraries(oat  PUBLIC controller-lib PUBLIC oatpp::oatpp PUBLIC oatpp::oatpp-test )
add_dependencies(oat controller-lib)

set_target_properties(oat  PROPERTIES
        CXX_STANDARD 11
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
)


# TODO: Add tests and install targets if needed.
