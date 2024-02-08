#include "includes.h"

// Easy -- #2000 -- accepted
class ReversePrefix {
public:
    static string reversePrefix(string word, char ch) {
        string ans;
        string temp;
        int index = 0;
        
        if (word.find(ch) == string::npos)
            return word;

        for (auto s : word)
        {
            if (s == ch)
                break;

            index++;
        }

        temp = word.substr(0, index+1);

        for (int j = index+1; j >= 0; j--)
            ans += temp[j];


        for (int i = index + 1; i < word.size(); i++)
            ans += word[i];

        return ans;
    }
};
