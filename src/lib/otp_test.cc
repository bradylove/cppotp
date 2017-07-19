#include "gtest/gtest.h"
#include "otp.h"

TEST(OTPTest, OTP) {
  OTP::Token t = OTP::Token("nftvbnyzojhhrgzt7lb3bo77mzbfp3r3");
  int64_t ts = 1444924687;
  std::string result = t.at(ts);

  EXPECT_EQ(result, "758729");
}
