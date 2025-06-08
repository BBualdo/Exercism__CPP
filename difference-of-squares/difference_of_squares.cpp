#include "difference_of_squares.h"
#include <complex>

namespace difference_of_squares {

    int square_of_sum(int num) {
        int sum = 0;
        for (int i = 1; i <= num; i++) {
            sum += i;
        }

        return static_cast<int>(std::pow(sum, 2));
    }

    int sum_of_squares(int num) {
        int sum = 0;
        for (int i = 1; i <= num; i++) {
            sum += static_cast<int>(std::pow(i, 2));
        }

        return sum;
    }

    int difference(int num) {
        return square_of_sum(num) - sum_of_squares(num);
    }

}  // namespace difference_of_squares
