cmake_minimum_required(VERSION 3.0.0)

add_library(otp otp.cc)
add_executable(otp_test otp_test.cc ${gtest_SOURCE_DIR}/src/gtest_main.cc otp.h)
add_test(NAME otp_test COMMAND otp_test)

target_include_directories(otp PUBLIC ${cppcodec_SOURCE_DIR} SYSTEM crypto)
target_link_libraries(otp crypto)
target_link_libraries(otp_test otp gtest_main)


