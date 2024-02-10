#include "includes.h"

// Easy -- #1356 -- accepted
class SortByNumberOfBits {
public:
    static vector<int> sortByBits(vector<int>& arr) {
        map<int, vector<int>> temp;
        vector<int> ans;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++)
        {
            temp[countBits(arr[i])].push_back(arr[i]);
        }

        for (auto entry : temp)
        {
            for (int j = 0; j < entry.second.size(); j++)
                ans.push_back(entry.second[j]);
        }

        return ans;

    }

    static int countBits(int n) {
        int count = 0;

        while (n > 0)
        {
            if (n % 2 != 0)
                count++;

            n /= 2;
        }

        return count;
    }

};