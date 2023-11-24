#include <vector>
#include <string>

using namespace std;

// medium (problem no. 2353) design a food rating system
class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        _foods = foods;
        _cuisines = cuisines;
        _ratings = ratings;
    }

    void changeRating(string food, int newRating) {
        for (int i = 0; i < _foods.size(); i++)
        {
            if (_foods[i].compare(food) == 0)
                _ratings[i] = newRating;
        }
    }

    string highestRated(string cuisine) {
        vector<int> foodOfCuisine;
        int indexOfHighestRated = 0, highestRatingValue = 0;

        // get list of food that are of that cuisine
        for (int i = 0; i < _foods.size(); i++)
        {
            if (!_cuisines[i].compare(cuisine))     // returns 0 if equal
                foodOfCuisine.push_back(i);
        }

        for (int i = 0; i < foodOfCuisine.size(); i++)
        {
            if (_ratings[foodOfCuisine[i]] > highestRatingValue)
            {
                highestRatingValue = _ratings[foodOfCuisine[i]];
                indexOfHighestRated = foodOfCuisine[i];
            }

            if ((highestRatingValue > 0) && (_ratings[foodOfCuisine[i]] == highestRatingValue))
            {
                if (_foods[indexOfHighestRated].compare(_foods[foodOfCuisine[i]]) < 0)
                    indexOfHighestRated = foodOfCuisine[i];
            }
        }

        return _foods[indexOfHighestRated];
    }

private:
    vector<string> _foods;
    vector<string> _cuisines;
    vector<int> _ratings;
};