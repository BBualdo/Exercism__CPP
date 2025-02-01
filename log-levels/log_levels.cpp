#include <string>
using namespace std;

namespace log_line {
    string message(string line) {
        int start_index = line.find(" ");
        return line.substr(start_index + 1);
    }

    string log_level(string line) {
        int end_index = line.find("]");
        return line.substr(1, end_index - 1);
    }

    string reformat(string line) {
        return message(line) + " (" + log_level(line) + ")";
    }
}
