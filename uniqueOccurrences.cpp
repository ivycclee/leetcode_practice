using namespace std;

#include <vector>
#include <map>
#include <set>

// no. 1207 - unique number of occur (easy) [ submitted && accepted ]
class UniqueOccurrences
{
public:
	static bool uniqueOccurrences(vector<int>& arr) {
		int arrSize = arr.size();
		map<int, int> occurrencesCount;
		set<int> occurrences;

		for (int i = 0; i < arrSize; i++)
		{
			occurrencesCount[arr[i]]++;
		}

		for (auto pair : occurrencesCount)
		{
			occurrences.insert(pair.second);
		}

		return (occurrences.size() == occurrencesCount.size());
	}
};
