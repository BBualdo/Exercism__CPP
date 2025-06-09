#pragma once
#include <optional>
#include <string>

namespace hexadecimal {
    int convert(std::string hex);
    std::optional<std::string> try_hex_to_binary(char hex);
    int binary_to_decimal(std::string binary);
}  // namespace hexadecimal
