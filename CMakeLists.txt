# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("oat")

# Include sub-projects.
add_subdirectory ("oat")
add_subdirectory ("controller")
