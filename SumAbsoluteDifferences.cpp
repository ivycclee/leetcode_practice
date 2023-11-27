#include <vector>

using namespace std;

// medium - sum of absolute differences in a sorted array, nov 25 daily challenge
// this works but not accepted due to exceeding time limit
class Differences {
public:
    static vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> results;
        int temp;

        for (int i = 0; i < nums.size(); i++)
        {
            temp = 0;

            for (int j = 0; j < nums.size(); j++)
                temp += abs(nums[i] - nums[j]);
      
            results.push_back(temp);
        }

        return results;
    }
};
