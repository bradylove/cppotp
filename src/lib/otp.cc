#include <string>
#include <cppcodec/base32_default_rfc4648.hpp>
#include <openssl/hmac.h>
#include "otp.h"
#include <iostream>
#include <cstring>

OTP::Token::Token() {
}

OTP::Token::Token(std::string t) {
    secret = base32::decode(t);
}

std::string OTP::Token::at(int64_t ts) {
    // Get hmac, secret is key, timestamp / period is data
//    unsigned char data[8];

    std::cout << "Timestamp: " << ts << std::endl;

    ts = ts / 30;

    std::cout << "Div: " << ts << std::endl;

    std::vector<unsigned char> data;

    for (int i = 56; i >= 0; i -= 8) {
        data.push_back((ts >> i) & 0xFF);
    }


    unsigned char* digest;
    digest = HMAC(EVP_sha1(), secret.data(), secret.size(), data.data(), data.size(), NULL, NULL);

    char offset = digest[sizeof(digest)-1];

    for (int i = 0; i < 8; i++) {
        std::cout << i << ": " << int(data[i]) << std::endl;
    }

    std::cout << "Offset: " << uint8_t(offset) << std::endl;

    int64_t code = (digest[offset] & 0x7f) << 24 |
                   (digest[offset+1] & 0xff) << 16 |
                   (digest[offset+2] & 0xff) << 8 |
                   (digest[offset+3] & 0xff);

    std::cout << "Code: " << code << std::endl;

    int64_t digits = code % 1000000;
    std::cout << "Digits: " << digits << std::endl;

    return "";
}

std::string OTP::Token::to_string() {
    return base32::encode(secret);
}