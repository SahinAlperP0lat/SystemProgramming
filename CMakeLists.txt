cmake_minimum_required(VERSION 3.10)
project(SystemProgramming)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

include_directories(
    include
    ${PQXX_INCLUDE_DIRS}
)

add_executable(system_program
    src/main.cpp
    src/db.cpp
)

target_link_libraries(system_program
    ${PQXX_LIBRARIES}
)
