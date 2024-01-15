using namespace std;

#include <vector>
#include <map>

// attempted - time limit exceeded on test case 98
class FindWinners
{
public:
	static vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        ans.resize(2);
        int arrSize = matches.size();
        map<int, pair<int, int>> winLossCount; // wins and losses
        int highestNumPlayer = 0;

        for (int i = 0; i < arrSize; i++) {
            winLossCount[matches[i][0]].first++;  // wins
            winLossCount[matches[i][1]].second++; // losses
        }

        for (int j = 1; j <= winLossCount.size(); j++) {
            if (winLossCount[j].second == 0 && winLossCount[j].first != 0)
                ans[0].push_back(j);

            if (winLossCount[j].second == 1)
                ans[1].push_back(j);
        }

        return ans;
	}
};
