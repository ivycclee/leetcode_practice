using namespace std;

#include <vector>
#include <string>

// no 1662 (easy) [ accepted ]
class ArrayStringsEquivalent {
public:
    static bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string fullword1, fullword2;

        for (string s : word1)
            fullword1.append(s);

        for (string s : word2)
            fullword2.append(s);

        return (fullword1.compare(fullword2) == 0);

    }
};