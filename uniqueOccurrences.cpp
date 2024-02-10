#include "includes.h"

// no. 1207 - unique number of occur (easy) [ submitted && accepted ]
class UniqueOccurrences
{
public:
	static bool uniqueOccurrences(vector<int>& arr) {
		auto arrSize = arr.size();
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
