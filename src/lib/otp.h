#include <string>

namespace otp {
  class token {
    public:
      token();
      token(std::string);

      std::string at(int);

    private:
      std::string myToken;
  };
}
