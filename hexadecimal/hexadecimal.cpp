#include "hexadecimal.h"

#include <algorithm>
#include <complex>
#include <map>

namespace hexadecimal {
    int convert(std::string hex) {
        std::string hex_in_binary{};

        for (char c : hex) {
            // convert each char (hex digit) to binary
            std::optional<std::string> result = try_hex_to_binary(c);
            if (result) {
                // merge with existing binary
                hex_in_binary += *result;
            } else {
                return 0;
            }
        }

        return binary_to_decimal(hex_in_binary);
    }

    std::optional<std::string> try_hex_to_binary(char hex) {
        std::map<char, std::string> hex_to_binary_map {
            {'0', "0000"},
            {'1', "0001"},
            {'2', "0010"},
            {'3', "0011"},
            {'4', "0100"},
            {'5', "0101"},
            {'6', "0110"},
            {'7', "0111"},
            {'8', "1000"},
            {'9', "1001"},
            {'a', "1010"},
            {'b', "1011"},
            {'c', "1100"},
            {'d', "1101"},
            {'e', "1110"},
            {'f', "1111"},
        };

        try {
            return hex_to_binary_map.at(hex);
        } catch (...) {
            return std::nullopt;
        }
    }

    int binary_to_decimal(std::string binary) {
        int result{};

        for (int i = static_cast<int>(binary.length()); i >= 0; i--) {
            int value = binary[i - 1] - '0';
            if (value == 1) {
                int pow = static_cast<int>(binary.length()) - i;
                result += static_cast<int>(std::pow(2, pow));
            }
        }

        return result;
    }

}  // namespace hexadecimal
