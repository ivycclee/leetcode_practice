#include "includes.h"

// Easy -- #169
class MajorityElement {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> freq;
        int min = nums.size() / 2;

        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;

            if (freq[nums[i]] > min)
                return nums[i];
        }

    }
};