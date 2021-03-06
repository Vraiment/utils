# Basic project configuration
CMAKE_MINIMUM_REQUIRED(VERSION 3.9.0)
PROJECT(VCppUtils VERSION 0.0.1)

# Set the relevant variables for dirs
SET(V_CPP_UTILS_SRC_DIR "${VCppUtils_SOURCE_DIR}/src")
SET(V_CPP_UTILS_TST_DIR "${VCppUtils_SOURCE_DIR}/tst")
SET(V_CPP_UTILS_OUTPUT_DIR ".")
SET(V_CPP_UTILS_OUTPUT_SRC_DIR "${V_CPP_UTILS_OUTPUT_DIR}/src")

# Set another constats
SET(V_CPP_UTILS_CPP_STD "c++11")

# Set C++ config file
CONFIGURE_FILE(
    "${V_CPP_UTILS_SRC_DIR}/VCppConfig.hpp.in"
    "${V_CPP_UTILS_OUTPUT_SRC_DIR}/VCppConfig.hpp"
)

# Set up flags
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=${V_CPP_UTILS_CPP_STD}")

# Add unit tests
ADD_SUBDIRECTORY("tst")

# Define the library target
FILE(GLOB V_CPP_UTILS_FILES
    "${V_CPP_UTILS_SRC_DIR}/*.hpp"
    "${V_CPP_UTILS_SRC_DIR}/*.cpp"
)
ADD_LIBRARY("${PROJECT_NAME}" "${V_CPP_UTILS_FILES}")
