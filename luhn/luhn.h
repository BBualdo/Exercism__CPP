#pragma once
#include <string>

namespace luhn {
    bool valid(std::string card_number);
    std::string remove_spaces(std::string& card_number);
    bool check_if_all_digits(const std::string& card_number);
    std::string double_every_second(std::string& card_number);
    int sum_digits(const std::string& card_number);
}  // namespace luhn
