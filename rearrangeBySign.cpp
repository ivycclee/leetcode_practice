#include "includes.h"

// Medium -- #2149 -- accepted
class RearrangeBySign {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> pos;
        queue<int> neg;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                neg.push(nums[i]);

            else if (nums[i] > 0)
                pos.push(nums[i]);
        }

        nums.clear();

        while (!pos.empty())
        {
            nums.push_back(pos.front());
            pos.pop();
            nums.push_back(neg.front());
            neg.pop();
        }

        return nums;
    }
};
