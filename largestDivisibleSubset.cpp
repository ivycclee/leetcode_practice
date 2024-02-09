#include "includes.h"

// Medium -- #368 -- accepted (this was hard !)
class LargestDivisibleSubset {
public:
    static vector<int> largestDivisibleSubset(vector<int>& nums) {
        auto n = nums.size();
        int temp_max = 1;
        int previous_value = -1;
        
        vector<int> ans;
        vector<int> temp(n, 1);

        if (n == 1 || n == 0)
            return nums;

        sort(nums.begin(), nums.end());

        for (int current = 0; current < n; current++)
        {
            for (int trailer = 0; trailer < current; trailer++)
            {
                if ((nums[current] % nums[trailer] == 0) && (temp[trailer] + 1 > temp[current]))
                {
                    temp[current] = temp[trailer] + 1;

                    if (temp[current] > temp_max)
                        temp_max = temp[current];
                }
            }
        }

        for (auto i = n-1; i >= 0; i--)
        {
            if ((temp[i] == temp_max) && (previous_value == -1 || previous_value % nums[i] == 0))
            {
                ans.push_back(nums[i]);
                temp_max--;
                previous_value = nums[i];
            }
        }

        return ans;
    }

};