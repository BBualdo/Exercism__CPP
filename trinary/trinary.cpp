#include "trinary.h"

#include <algorithm>
#include <complex>
#include <iostream>

namespace trinary {
    int to_decimal(std::string str) {
        // check if str contains only numeric values
        for (char c : str) {
            if (!std::isdigit(c)) return 0;
        }

        int result{};
        // reverse string to fix index
        std::reverse(str.begin(), str.end());

        for (std::size_t i = 0; i < str.length(); i++) {
            // value * 3^index
            result += (str[i] - '0') * pow(3, i);
        }

        return result;
    }

}  // namespace trinary
