#include "includes.h"

// Medium -- #49 -- daily challenge feb 06
class GroupAnagrams {
public:
    static vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> anagrams;
        string key = "";

        for (auto s : strs)
        {
            key = s;

            sort(key.begin(), key.end());

            anagrams[key].push_back(s);
            
        }

        for (auto pair : anagrams)
        {
            ans.push_back(pair.second);
        }
        
        return ans;
        
    }
};
