#include "rotational_cipher.h"

namespace rotational_cipher {
    std::string rotate(std::string input, int key) {
        // normalize key
        key = key % 26;
        std::string output{};

        for (char c : input) {
            if (std::isalpha(c)) {
                int max;
                if (std::isupper(c)) {
                    // if char is uppercase you must shift between 65-90
                    max = 90;
                } else {
                    // if char is lowercase you must shift between 97-122
                    max = 122;
                }

                int rotated_char = c + key;
                if (rotated_char > max) {
                    rotated_char -= 26;
                }
                output += static_cast<char>(rotated_char);
            } else {
                output += c;
            }
        }

        return output;
    }
}  // namespace rotational_cipher
