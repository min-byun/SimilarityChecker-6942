#include <string>
#include <vector>

#define ALPHA_CNT 26

using namespace std;

class SimilarityLength {
public:
	int checkLength(string str_A, string str_B) {
		calcLength(str_A, str_B);
		calcMinMaxLength();
		if (checkSameLength()) return MAX_SCORE_LENGTH;
		if (check2xDiffLengh())return MIN_SCORE;
		return calculateSocre();
	}
private:
	const int MAX_SCORE_LENGTH = 60;
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
};

class SimilarityAlphabet {
public:
	int checkAlphabet(string str_A, string str_B) {
		cntAlphabetStr.resize(ALPHA_CNT);
		cntAlphabetStrA = countAlphabetStr(str_A);
		cntAlphabetStrB = countAlphabetStr(str_B);

		return getAlphabetScore();
	}

private:
	vector<bool> cntAlphabetStrA;
	vector<bool> cntAlphabetStrB;
	vector<bool> cntAlphabetStr;

	const int MAX_SCORE_ALPHABET = 40;

	vector<bool> countAlphabetStr(string str) {
		vector<bool> cnt;
		cnt.resize(ALPHA_CNT);

		for (auto ch : str) {
			int idx = ch - 'A';
			cntAlphabetStr[idx] = cnt[idx] = true;
		}
		return cnt;
	}

	int getAlphabetScore() {
		int sameCnt = 0;
		int totalCnt = 0;
		for (int i = 0; i < ALPHA_CNT; i++) {
			if (cntAlphabetStr[i] == false) continue;
			totalCnt++;
			if (cntAlphabetStrA[i] == cntAlphabetStrB[i])
				sameCnt++;
		}

		return (sameCnt * MAX_SCORE_ALPHABET) / totalCnt;
	}
};

class SimilarityChecker {
public:
	int getScore(string str_A, string str_B) {
		return sLength.checkLength(str_A, str_B) + sAlphabet.checkAlphabet(str_A, str_B);
	}
private:
	SimilarityLength sLength;
	SimilarityAlphabet sAlphabet;
};