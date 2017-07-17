#include "gtest/gtest.h"
#include "lib/otp.h"

TEST(OTPTest, OTP) {
  otp::token t = otp::token("nftvbnyzojhhrgzt7lb3bo77mzbfp3r3");
  std::string result = t.at(1444924687);

  EXPECT_EQ(result, "758729");
}
