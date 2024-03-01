#include "includes.h"

// Easy - #2864 -- accepted
class MaxOddBinaryNumber {
public:
	static string MaxOddBinary(string s) {
		auto oneCounts = 0;
		auto stringSize = s.size();
		string ans = "";

		if (s.size() == 1) return "1";

		for (const char& ch : s)
		{
			if (ch == '1')
				oneCounts++;
		}

		if (oneCounts == 1)
			return "001";

		while (oneCounts > 1)
		{
			ans.append("1");
			oneCounts--;
		}

		while (ans.size() < stringSize-1)
		{
			ans.append("0");
		}

		ans.append("1");

		return ans;
	}
};
