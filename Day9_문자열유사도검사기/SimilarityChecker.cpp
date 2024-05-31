#include <string>

using namespace std;

class SimilarityChecker {
public:
	int checkLength(string str_A, string str_B) {
		calcLength(str_A, str_B);
		calcMinMaxLength();
		if (checkSameLength()) return MAX_SCORE;
		if (check2xDiffLengh())return MIN_SCORE;
		return calculateSocre();
	}
private:
	const int MAX_SCORE = 60;
	const int MIN_SCORE = 0;
	int len_A = 0;
	int len_B = 0;
	int len_min = 0;
	int len_max = 0;

	void calcLength(string str_A, string str_B) {
		len_A = str_A.size();
		len_B = str_B.size();
	}

	void calcMinMaxLength() {
		len_min = min(len_A, len_B);
		len_max = max(len_A, len_B);
	}

	bool checkSameLength() {
		return (len_A == len_B);
	}

	bool check2xDiffLengh() {
		return (len_max >= len_min * 2);
	}

	int calculateSocre() {
		return (1 - (double)(len_max - len_min) / len_min) * MAX_SCORE;
	}
};