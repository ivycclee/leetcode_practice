#include "includes.h"

// Easy -- #2108 -- accepted
class FirstPalindrome {
public:
    string firstPalindrome(vector<string>& words) {
        bool found = true;
        
        for (const auto& s : words)
        {
            found = true;

            for (int i = 0; i < s.size() / 2; i++)
            {
                if (s[i] != s[s.size() - 1 - i])
                {
                    found = false;
                    break;
                }
            }

            if (found)  
                return s;
        }

        return "";
    }
};
