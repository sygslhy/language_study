cmake_minimum_required(VERSION 3.10)
project(model)


set(OUR_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(TARGET model)
set(PUBLIC_HDR_DIR ${OUR_DIR}/include)
set(SRC_DIR ${OUR_DIR}/src)


# public headers dependencies
set(PUBLIC_HDRS ${PUBLIC_HDR_DIR}/model/VerbConjModel.h
)

# private headers dependencies
set(PRIVATE_HDRS)

# sources dependencies

# we're building a library
add_library(${TARGET} INTERFACE ${PRIVATE_HDRS} ${PUBLIC_HDRS} ${SRCS})

# specify where the public headers of this library are
target_include_directories(
    ${TARGET}
    INTERFACE ${PUBLIC_HDR_DIR} ${PRIVATE_HDR_DIR}
)

