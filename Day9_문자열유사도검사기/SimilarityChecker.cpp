#include <string>

using namespace std;

class SimilarityChecker {
public:
	int checkLength(string str_A, string str_B) {
		int score = MIN_SCORE;
		int len_A = str_A.size();
		int len_B = str_B.size();
		int len_min = (len_A < len_B) ? len_A : len_B;
		int len_max = (len_A < len_B) ? len_B : len_A;
		if (len_A == len_B)
			score = MAX_SCORE;
		else if (len_max >= len_min * 2)
			score = MIN_SCORE;
		else
			score = (1 - (double)(len_max - len_min) / len_min) * 60;
		return score;
	}
private:
	const int MAX_SCORE = 60;
	const int MIN_SCORE = 0;
};