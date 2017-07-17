#include <string>
#include "otp.h"

otp::token::token() {
  myToken = "";
}

otp::token::token(std::string t) {
  myToken = t;
}

std::string otp::token::at(int) {
  return "";
}
