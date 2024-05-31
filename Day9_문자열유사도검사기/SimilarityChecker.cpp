#include <string>

using namespace std;

class SimilarityChecker {
public:
	int checkLength(string str_A, string str_B) {
		int len_A = str_A.size();
		int len_B = str_B.size();

		len_min = (len_A < len_B) ? len_A : len_B;
		len_max = (len_A < len_B) ? len_B : len_A;

		if (checkSameLength(len_A,len_B))
			return MAX_SCORE;
		if (check2xDiffLengh())
			return MIN_SCORE;

		return calculateSocre();
	}
private:
	const int MAX_SCORE = 60;
	const int MIN_SCORE = 0;
	int len_min = 0;
	int len_max = 0;

	bool checkSameLength(int len_A, int len_B) {
		return (len_A == len_B);
	}

	bool check2xDiffLengh() {
		return (len_max >= len_min * 2);
	}

	int calculateSocre() {
		return (1 - (double)(len_max - len_min) / len_min) * MAX_SCORE;
	}
};