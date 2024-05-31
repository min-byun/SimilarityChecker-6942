#include <string>
#include <vector>

#define ALPHA_CNT 26

using namespace std;

class SimilarityChecker {
public:
	int checkLength(string str_A, string str_B) {
		calcLength(str_A, str_B);
		calcMinMaxLength();
		if (checkSameLength()) return MAX_SCORE_LENGTH;
		if (check2xDiffLengh())return MIN_SCORE;
		return calculateSocre();
	}

	int checkAlphabet(string str_A, string str_B) {
		int score = 0;
		for (auto ch : str_A) {
			int idx = ch - 'A';
			cntAlphabetStr[idx] = cntAlphabetStrA[idx] = true;
		}
		for (auto ch : str_B) {
			int idx = ch - 'A';
			cntAlphabetStr[idx] = cntAlphabetStrB[idx] = true;
		}


		int sameCnt = 0;
		int totalCnt = 0;
		for (int i = 0; i < ALPHA_CNT; i++) {
			if (cntAlphabetStr[i] == false) continue;
			totalCnt++;
			if (cntAlphabetStrA[i] == cntAlphabetStrB[i])
				sameCnt++;
		}

		score = (double)(sameCnt * MAX_SCORE_ALPHABET) / totalCnt;
		return score;
	}
private:
	const int MAX_SCORE_LENGTH = 60;
	const int MAX_SCORE_ALPHABET = 40;
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
		return (1 - (double)(len_max - len_min) / len_min) * MAX_SCORE_LENGTH;
	}

	bool cntAlphabetStrA[ALPHA_CNT] = { 0, };
	bool cntAlphabetStrB[ALPHA_CNT] = { 0, };
	bool cntAlphabetStr[ALPHA_CNT] = { 0, };
};