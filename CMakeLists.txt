project(Project5 CXX)
cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLGAS ${CMAKE_CXX_FLAGS})

add_executable(project5	
	main.cpp
	BST.cpp
	Tree_template.cpp
	ListSearch.cpp
	)

set(files main.cpp BST.cpp BST.hpp Tree_template.hpp Tree_template.cpp ListSearch.cpp ListSearch.hpp)

add_custom_target(printout
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMAND a2ps -Afill -o- ${files} | ps2pdf - ${CMAKE_BINARY_DIR}/printout.pdf)
