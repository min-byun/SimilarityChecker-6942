#include "pch.h"
#include "../Day9_문자열유사도검사기/SimilarityChecker.cpp"

#include <string>

using namespace std;

TEST(SimilarityCheckerTest, LegnthSameTest) {
	SimilarityChecker similarityChecker;
	string str_A = "ABC";
	string str_B = "BLT";

	int expect = 60;
	int similarity = similarityChecker.checkLength(str_A, str_B);

	EXPECT_EQ(expect, similarity);
}

TEST(SimilarityCheckerTest, Legnth2xDiffTest) {
	SimilarityChecker similarityChecker;
	string str_A = "ABC";
	string str_B = "BLTABC";

	int expect = 0;
	int similarity = similarityChecker.checkLength(str_A, str_B);

	EXPECT_EQ(expect, similarity);
}