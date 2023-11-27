#include <vector>
#include <string>
#include <map>

using namespace std;

// medium (problem no. 2353) design a food rating system

// this works, but is not accepted due to exceeding time limit on a test case
class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        /*_foods = foods;
        _cuisines = cuisines;
        _ratings = ratings;*/
        for (int i = 0; i < foods.size(); i++)
        {
            cuisineFood[cuisines[i]].push_back(foods[i]);
            foodRating.insert( { foods[i], ratings[i] });
        }
    }

    void changeRating(string food, int newRating) {
            foodRating[food] = newRating;
        
    }

    string highestRated(string cuisine) {
        vector<string> foodsOfCuisine = cuisineFood.at(cuisine);
        int currentHighestRating = 0;
        string highestRatedFood = "";

        for (int i = 0; i < foodsOfCuisine.size(); i++)
        {
            if (foodRating.at(foodsOfCuisine[i]) > currentHighestRating)
            {
                currentHighestRating = foodRating.at(foodsOfCuisine[i]);
                highestRatedFood = foodsOfCuisine[i];
            }

            if (foodRating.at(foodsOfCuisine[i]) == currentHighestRating)
            {
                if (foodsOfCuisine[i].compare(highestRatedFood) < 0)
                    highestRatedFood = foodsOfCuisine[i];
            }

        }

        return highestRatedFood;
    }

private:
    /*vector<string> _foods;
    vector<string> _cuisines;
    vector<int> _ratings;*/
    
    map<string, vector<string>> cuisineFood;
    map<string, int> foodRating;
};