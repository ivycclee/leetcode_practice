using namespace std;

#include <vector>
#include <map>

// no. 2225 [ accepted ]
class FindWinners
{
public:
	static vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        ans.resize(2);
        int arrSize = matches.size();
      
        map<int, int> loss;

        for (int i = 0; i < arrSize; i++)
        {
            loss[matches[i][0]] += 0;                // instantiatiation
            loss[matches[i][1]] += 0;                // instantiatiation
            
            loss[matches[i][1]]++;
        }

        for (auto lossCount : loss)
        {
            if (lossCount.second == 0)
                ans[0].push_back(lossCount.first);

            else if (lossCount.second == 1)
                ans[1].push_back(lossCount.first);
        }

        return ans;
	}
};
