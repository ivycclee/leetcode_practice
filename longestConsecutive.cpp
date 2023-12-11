#include <vector>
#include <algorithm>

using namespace std;

// Problem 128 - medium
class LongestConsecutiveSequence {
public:
    static int longestConsecutive(vector<int>& nums) {
        int count = 1;
        int highestcount = 0;
        sort(nums.begin(), nums.end());

        if (nums.size() == 0)
            return 0;


        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] != nums[i + 1])
            {
                if (nums[i] + 1 == nums[i + 1])
                    count++;

                else
                {
                    highestcount = max(count, highestcount);
                    count = 1;
                }
            }
        }

        return max(count, highestcount);
    }
};