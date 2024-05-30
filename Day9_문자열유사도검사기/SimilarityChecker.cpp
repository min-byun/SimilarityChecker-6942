#include <string>

using namespace std;

class SimilarityChecker {
public:
	int checkLength(string str_A, string str_B) {
		int score = 0;
		int len_A = str_A.size();
		int len_B = str_B.size();
		int len_min = (len_A < len_B) ? len_A : len_B;
		int len_max = (len_A < len_B) ? len_B : len_A;
		if (len_A == len_B)
			score = 60;
		if (len_max >= len_min * 2)
			score = 0;
		return score;
	}
};