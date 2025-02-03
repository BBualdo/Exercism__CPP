#pragma once
#include <string>
#include <vector>

using namespace std;

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

    int preparationTime(const vector<string>& layers, const int timePerLayer = 2);
    amount quantities(const vector<string>& layers);
    void addSecretIngredient(vector<string>& myList, const vector<string>& friendsList);
    void addSecretIngredient(vector<string>& myList, const string& secretIngredient);
    vector<double> scaleRecipe(const vector<double>& quantitiesForTwo, int desiredPortions);
}  // namespace lasagna_master
