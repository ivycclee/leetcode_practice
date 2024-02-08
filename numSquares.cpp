#include "includes.h"

// Medium -- #279 -- accepted
class NumSquares {
public:
	static int numSquares(int n) {
		// Lagrange's theorem -- every positive number 
		// can be represented as the sum of (at most) 4 squares
		int i, y;

		while (n % 4 == 0)  
			n /= 4;

		if (n % 8 == 7) return 4;

		auto loopMax = sqrt(n);

		for (i = 0; i < sqrt(n); i++)
		{
			y = sqrt(n - (i * i));

			if ((i * i) + (y * y) == n) {
				if (i == 0 || y == 0) return 1;
				else return 2;
			}
		}

		return 3;
	}
};
