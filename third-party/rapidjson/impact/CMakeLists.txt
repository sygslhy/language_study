cmake_minimum_required(VERSION 3.10)
project(rapidjson)

set(LIB_MAJOR_VERSION "1")
set(LIB_MINOR_VERSION "1")
set(LIB_PATCH_VERSION "0")
set(LIB_VERSION_STRING "${LIB_MAJOR_VERSION}.${LIB_MINOR_VERSION}.${LIB_PATCH_VERSION}")

set(OUR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)

set(TARGET rapidjson)
set(PUBLIC_HDR_DIR ${OUR_DIR}/include)

# we're building a library
add_library(${TARGET} INTERFACE)

# specify where the public headers of this library are
target_include_directories(${TARGET} INTERFACE ${PUBLIC_HDR_DIR})

# Enable std::string APIs in rapidjson
target_compile_definitions(${TARGET} INTERFACE RAPIDJSON_HAS_STDSTRING=1)
