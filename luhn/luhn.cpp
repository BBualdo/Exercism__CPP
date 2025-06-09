#include "luhn.h"

namespace luhn {
    bool valid(std::string card_number) {
        card_number = remove_spaces(card_number);

        if (card_number.length() <= 1)
            return false;

        if (!check_if_all_digits(card_number))
            return false;

        card_number = double_every_second(card_number);

        // if sum % 10 == 0 is valid, else not
        return sum_digits(card_number) % 10 == 0;
    }

    std::string remove_spaces(std::string& card_number) {
        for (char c : card_number) {
            if (std::isspace(c)) {
                card_number.erase(card_number.find(c), 1);
            }
        }

        return card_number;
    }

    bool check_if_all_digits(const std::string& card_number) {
        for (char c : card_number) {
            if (!std::isdigit(c))
                return false;
        }

        return true;
    }

    std::string double_every_second(std::string& card_number) {
        for (int i = static_cast<int>(card_number.length()); i >= 0; i -= 2) {
            // double every second number (looping backwards)
            int doubled_number = (card_number[i] - '0') * 2;

            // if doubled number is > 9, then substract 9 from result
            if (doubled_number > 9)
                doubled_number -= 9;

            card_number[i] = doubled_number + '0';
        }

        return card_number;
    }

    int sum_digits(const std::string& card_number) {
        int sum{0};

        for (char c : card_number) {
            sum += c - '0';
        }

        return sum;
    }

}  // namespace luhn
