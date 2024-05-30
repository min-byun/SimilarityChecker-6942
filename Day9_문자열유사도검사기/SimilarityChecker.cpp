#include <string>

using namespace std;

class SimilarityChecker {
public:
	int checkLength(string str_A, string str_B) {
		int score = 0;
		int len_A = str_A.size();
		int len_B = str_B.size();
		if (len_A == len_B)
			score = 60;
		return score;
	}
};