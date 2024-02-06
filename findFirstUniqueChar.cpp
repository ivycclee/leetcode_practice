#include "includes.h"

// Easy -- no. 387 -- accepted
class FindFirstUniqueChar {
public:
    static int firstUniqChar(string s) {
        unordered_map<char, int> charCount;

        for (char c : s)
        {
            charCount[c]++;             // count freq of each letter
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (charCount[s[i]] == 1)
                return i;
        }

        return -1;
    }
};