cmake_minimum_required(VERSION 3.0.0)
project(DD VERSION 0.0.1)

include(CTest)
enable_testing()

set(SOURCES
    src/main.cpp
    src/terminal.cpp
    src/menu.cpp
)
set(HEADERS
    src/terminal.h
    src/menu.h
)

add_executable(DD ${SOURCES} ${HEADERS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
