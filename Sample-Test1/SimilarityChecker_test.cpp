#include "pch.h"
#include "../Day9_���ڿ����絵�˻��/SimilarityChecker.cpp"

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