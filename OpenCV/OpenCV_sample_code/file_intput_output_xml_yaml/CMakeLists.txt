cmake_minimum_required(VERSION 3.17)
project(file_intput_output_xml_yaml)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV REQUIRED)

add_executable(fileIO ${PROJECT_SOURCE_DIR}/src/fileIO.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

target_link_libraries(fileIO ${OpenCV_LIBS})