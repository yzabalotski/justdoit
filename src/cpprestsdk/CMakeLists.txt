cmake_minimum_required (VERSION 3.7)
project (cpprestsdk-server)

FIND_PACKAGE (Boost COMPONENTS system REQUIRED)
INCLUDE_DIRECTORIES ( ${Boost_INCLUDE_DIR} )

find_package (cpprestsdk REQUIRED)

add_executable (cpprestsdk-server server.cpp)
target_link_libraries (cpprestsdk-server PRIVATE ${Boost_LIBRARIES})
target_link_libraries (cpprestsdk-server PRIVATE cpprestsdk::cpprest)
