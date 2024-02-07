#include "includes.h"

// Medium -- # 451 -- acepted
class FrequencySort {
public:
    static string frequencySort(string s) {
        map<char, int> freqCount;
        vector<pair<int, char>> freq;
        string ans;
        int i;

        for (i = 0; i < s.size(); i++)
        {
            freqCount[s[i]]++;
        }

        for (auto pair : freqCount)
        {
            freq.push_back({ pair.second, pair.first });
        }

        sort(freq.rbegin(), freq.rend());                   // sort in deswcending

        for (auto entry : freq)
        {
            for (i = 0; i < entry.first; i++)
                ans += entry.second;
        }

        return ans;
    }

};
