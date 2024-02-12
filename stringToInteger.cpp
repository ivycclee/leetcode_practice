#include "includes.h"

// Medium -- #8
class StringToInteger {
public:
    static int myAtoi(string s) {
        int ans;
        bool isNeg = false;

        s.erase(remove_if(s.begin(), s.end(), isspace), s.end());    // remove whitespace



        return s.size();

    }
};