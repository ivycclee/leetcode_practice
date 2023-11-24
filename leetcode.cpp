#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include "FoodRatings.cpp"

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Medium
    static vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> returnVector;
        vector<vector<int>> tempMap;
        size_t rows = nums.size();
        size_t cols = 0;
        size_t count = 0;

        // iterate to find maximum num of cols
        for (int i = 0; i < rows; i++)
        {
            if (nums[i].size() > cols)
                cols = nums[i].size();
        }

        tempMap.resize(rows + cols);
        //returnVector.push_back(nums[0][0]);
        // vector 0 = (0,0)
        // vector 1 = (1,0) & (0,1)
        // vector 2 = (2,0) & (1,1) & (0,2)
        // i.e. the r+c index equals index of map
        for (size_t r = 0; r < rows; r++)
        {
            count = r;

            for (size_t c = 0; c < nums[r].size(); c++)
            {
                if (r + c == count)
                    tempMap[count].push_back(nums[r][c]);

                count++;
            }
        }

        // now populate return vector with correct order
        for (int i = 0; i < tempMap.size(); i++)
        {
            for (int j = (tempMap[i].size() - 1); j >= 0; j--)
            {
                returnVector.push_back(tempMap[i][j]);
            }
        }
        return returnVector;
    }

    // Medium
    static vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<int> tempArr;
        vector<bool> returnArr;
        bool tempBoolean;

        for (size_t i = 0; i < l.size(); i++)
        {
            // subarray
            tempArr.resize(r[i] - l[i] + 1);    // end - start + 1
            copy((nums.begin() + l[i]), (nums.begin() + 1 + r[i]), tempArr.begin());

            sort(tempArr.begin(), tempArr.end());       // sort first

            tempBoolean = true;

            for (int j = 0; j < tempArr.size() - 1; j++)
            {
                if ((tempArr[j + 1] - tempArr[j]) != (tempArr[1] - tempArr[0]))
                    tempBoolean = false;

            }
            returnArr.push_back(tempBoolean);

        }

        return returnArr;
    }

    // Easy (??????)
    int minDepth(TreeNode* root) {
        if (root == NULL) // base case
            return 0;

        if (root->left == NULL && root->right == NULL)  // leaf node found
            return 1;

        if (root->left == NULL)
            return 1 + minDepth(root->right);

        if (root->right == NULL)
            return 1 + minDepth(root->left);

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }

    // Easy (??????????)
    static bool repeatedSubstringPattern(string s) {
        string bigStr = s + s;
        return bigStr.substr(1, bigStr.length() - 2).find(s) != -1;
    }

    // Easy - implement stack using queue
    class MyStack {
    public:
        MyStack() {
            
        }

        void push(int x) {
            _q.push(x);
        }

        int pop() {
            int temp = top();
            for (int i = 0; i < _q.size(); i++)
            {
                if (!(i == _q.size()-1))
                    _q.push(_q.front());

                _q.pop();
            }
            return temp;
        }

        int top() {
            return _q.back();
        }

        bool empty() {
            return _q.empty();
        }
    private:
        queue<int> _q;
    };

    // Medium - maximum number of coins
    static int maxCoins(vector<int>& piles) {
        int coinsPerPerson = piles.size() / 3;
        int sum = 0;

        sort(piles.begin(), piles.end());       // sort in order

        for (int i = coinsPerPerson; i < piles.size(); i += 2)
            sum += piles[i];

       return sum;

    }

    
}; // end of Solution


int main(int argc, char const* argv[])
{
    vector<string> f{ "kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi" };
    vector<string> c{ "korean", "japanese", "japanese", "greek", "japanese", "korean" };
    vector<int> r{ 9, 12, 8, 15, 14, 7 };

    FoodRatings food{f, c, r};
    food.highestRated("korean");
    food.highestRated("japanese");
    food.changeRating("sushi", 16);
    food.highestRated("japanese");
    food.changeRating("ramen", 16);
    food.highestRated("japanese");

    return 0;
}
