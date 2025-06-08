#pragma once

#include <string>

namespace atbash_cipher {
    std::string encode(std::string input);

    std::string decode(std::string input);

    std::string split_by(std::string input, int by);
}  // namespace atbash_cipher
