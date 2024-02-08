#include "includes.h"

// Medium -- #3 -- accepted
class LongestSubstring {
public:
    static int lengthOfLongestSubstring(string s) {
        unordered_set<char> characters;
        int temp = 0;
        int leftIndex = 0, rightIndex;

        if (s == "") return 0;

        for (rightIndex = leftIndex; rightIndex < s.size(); rightIndex++)
        {
            if (characters.find(s[rightIndex]) == characters.end())             // if it doesn't exist, add to set
            {
                characters.insert(s[rightIndex]);
            }

            else
            {
                temp = max(temp, (int)characters.size());
                characters.clear();

                auto swap = leftIndex;
                leftIndex++;
                rightIndex = swap-1;
            }
        }   

        return max(temp, (int)characters.size());
    }
};
