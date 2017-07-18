cmake_minimum_required(VERSION 3.0.0)
project(cppotp)

########################
# Download external deps
########################
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
configure_file(CMakeLists.txt.in cppcodec-download/CMakeLists.txt)

######################
# Configure googletest
######################
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  #message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  #message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

######################
# Configure cppcodec
######################
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/cppcodec-download )
if(result)
  #message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/cppcodec-download )
if(result)
  #message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)
add_subdirectory(${CMAKE_BINARY_DIR}/cppcodec-src
                 ${CMAKE_BINARY_DIR}/cppcodec-build)

add_subdirectory(src)
add_subdirectory(third_party)
