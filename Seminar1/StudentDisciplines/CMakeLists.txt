cmake_minimum_required(VERSION 3.20)
project(StudentDisciplines)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(StudentDisciplines Tests/unitTests.cpp ElectiveDiscipline.cpp ElectiveDiscipline.h Student.h Student.cpp main.cpp Tests/ElectiveDisciplinesExtended.cpp Tests/ElectiveDisciplinesExtended.h)
target_link_libraries(StudentDisciplines gtest gtest_main)