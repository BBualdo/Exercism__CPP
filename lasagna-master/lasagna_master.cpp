#include "lasagna_master.h"

namespace lasagna_master {
    int preparationTime(const vector<string>& layers, const int timePerLayer)
    {
        return layers.size() * timePerLayer;
    }

    amount quantities(const vector<string>& layers)
    {
        amount needed{0, 0};

        for (const string& layer : layers)
        {
            if (layer == "sauce") needed.sauce += 0.2;
            if (layer == "noodles") needed.noodles += 50;
        }

        return needed;
    }

    void addSecretIngredient(vector<string>& myList, const vector<string>& friendsList)
    {
        myList[myList.size() - 1] = friendsList[friendsList.size() - 1];
    }

    void addSecretIngredient(vector<string>& myList, const string& secretIngredient)
    {
        myList[myList.size() - 1] = secretIngredient;
    }

    vector<double> scaleRecipe(const vector<double>& quantitiesForTwo, int desiredPortions)
    {
        vector<double> desiredQuantities{};
        desiredQuantities.reserve(quantitiesForTwo.size());

        for (double quantity : quantitiesForTwo)
        {
            desiredQuantities.emplace_back(quantity * (desiredPortions / 2.0));
        }

        return desiredQuantities;
    }


}  // namespace lasagna_master
