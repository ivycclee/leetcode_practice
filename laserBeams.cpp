#include <vector>
#include <string>

using namespace std;

// Medium -- no 2125 -- accepted
class LaserBeams {
public:
	static int numberOfBeams(vector<string>& bank) {
		vector<int> rowCounts;
		int temp = 0;
		int j = 0;

		if (bank.size() == 1) return 0;

		for (string s : bank)
		{
			temp = 0;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == '1')
					temp++;

			}
			if (temp != 0)
				rowCounts.push_back(temp);
		}

		temp = 0;

		if (rowCounts.size() == 1 || rowCounts.size() == 0) return 0;

		do {
			temp += rowCounts[j] * rowCounts[j + 1];

			j++;
		} while (j + 1 < rowCounts.size());

		return temp;
	}

};