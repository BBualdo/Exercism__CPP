#include <stdexcept>
#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

int vote_count(ElectionResult result)
{
    return result.votes;
}

void increment_vote_count(ElectionResult& result, int votes)
{
    result.votes += votes;
}

ElectionResult& determine_result(std::vector<ElectionResult>& final_count)
{
    // determine highest amount of votes
    int max_votes = 0;
    int index = 0;
    for (int i = 0; i < final_count.size(); i++)
    {
        if (final_count[i].votes > max_votes)
        {
            max_votes = final_count[i].votes;
            index = i;
        }
    }

    final_count[index].name = "President " + final_count[index].name;
    return final_count[index];
}
}  // namespace election