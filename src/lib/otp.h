#include <string>
#include <vector>

namespace OTP {
  class Token {
    public:
      Token();
      Token(std::string);

      std::string at(int64_t);
      std::string to_string();

    private:
      std::vector<uint8_t> secret;
  };
}
