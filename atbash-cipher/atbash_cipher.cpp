#include "atbash_cipher.h"

namespace atbash_cipher {
    std::string alphabeth = "abcdefghijklmnopqrstuvwxyz";
    std::string key = "zyxwvutsrqponmlkjihgfedcba";

    std::string encode(std::string input) {
        std::string output{};

        // lowercase each input letter and delete spaces and punctuation
        for (std::size_t i = 0; i < input.length(); i++) {
            if (std::isspace(input[i]) || std::ispunct(input[i])) {
                input.erase(input.find(input[i]), 1);
                i--;
            }
            input[i] = tolower(input[i]);
        }

        for (std::size_t i = 0; i < input.length(); i++) {
            if (std::isdigit(input[i])) {
                output += input[i];
            } else {
                output += key[alphabeth.find(input[i])];
            }
        }

        output = split_by(output, 5);

        return output;
    }

    std::string decode(std::string input) {
        std::string output{};

        for (std::size_t i = 0; i < input.length(); i++) {
            if (std::isspace(input[i])) {
                input.erase(input.find(input[i]), 1);
            }

            if (std::isdigit(input[i])) {
                output += input[i];
            } else {
                output += alphabeth[key.find(input[i])];
            }
        }

        return output;
    }

    std::string split_by(std::string input, int by) {
        std::string output{};

        for (std::size_t i = 1; i <= input.length(); i++) {
            output += input[i - 1];

            if (i != input.length() && i % (by) == 0) {
                output += ' ';
            }
        }

        return output;
    }

}  // namespace atbash_cipher
