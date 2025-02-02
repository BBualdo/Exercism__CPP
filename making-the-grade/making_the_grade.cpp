#include <array>
#include <string>
#include <vector>

using namespace std;

// Round down all provided student scores.
vector<int> round_down_scores(vector<double> student_scores) {
    vector<int> result;

    for (double student_score : student_scores)
    {
        result.emplace_back(static_cast<int>(student_score));
    }

    return result;
}

// Count the number of failing students out of the group provided.
int count_failed_students(vector<int> student_scores) {
    int result = 0;

    for (int score : student_scores)
    {
        if (score <= 40) result++;
    }

    return result;
}

// Create a list of grade thresholds based on the provided highest grade.
array<int, 4> letter_grades(int highest_score) {
    array<int, 4> result = {41, 0, 0, 0};
    int gap = (highest_score - 40) / 4;

    for (int i = 1; i < 4; i++)
    {
        result[i] = result[i - 1] + gap;
    }

    return result;
}

// Organize the student's rank, name, and grade information in ascending order.
vector<string> student_ranking(vector<int> student_scores, vector<string> student_names) {
    vector<string> result;

    for (int i = 0; i < student_scores.size(); i++)
    {
        string str = to_string(i + 1) + ". " + student_names[i] + ": " + to_string(student_scores[i]);
        result.emplace_back(str);
    }

    return result;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
string perfect_score(vector<int> student_scores, vector<string> student_names) {
    for (int i = 0; i < student_scores.size(); i++)
    {
        if (student_scores[i] == 100) return student_names[i];
    }

    return "";
}
