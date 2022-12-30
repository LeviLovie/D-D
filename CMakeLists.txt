cmake_minimum_required(VERSION 3.0.0)
project(DD VERSION 0.0.1)

include(CTest)
enable_testing()

set(SOURCES
    src/main.cpp
    src/terminal.cpp
    src/menu.cpp
    src/game.cpp
    src/newGameGetters.cpp
    src/subGame.cpp
    src/saving.cpp
)
set(HEADERS
    src/terminal.h
    src/menu.h
    src/game.h
    src/newGameGetters.h
    src/subGame.h
    src/saving.h
)

add_executable(DD ${SOURCES} ${HEADERS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
