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