cmake_minimum_required(VERSION 3.8)

add_executable(otp_test otp-test.cc ${gtest_SOURCE_DIR}/src/gtest_main.cc)
target_link_libraries(otp_test gtest_main)
add_test(NAME otp_test COMMAND otp_test)


