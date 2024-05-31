#include "pch.h"
#include "../Day9_문자열유사도검사기/SimilarityChecker.cpp"

#include <string>

using namespace std;

class SimilarityCheckerFixtrue : public testing::Test
{
public:
	SimilarityChecker similarityChecker;
};

TEST_F(SimilarityCheckerFixtrue, LegnthSameTest) {
	string str_A = "ABC";
	string str_B = "BLT";

	EXPECT_EQ(60, similarityChecker.checkLength(str_A, str_B));
}

TEST_F(SimilarityCheckerFixtrue, Legnth2xDiffTest1) {
	string str_A = "ABC";
	string str_B = "BLTABC";

	EXPECT_EQ(0, similarityChecker.checkLength(str_A, str_B));
}

TEST_F(SimilarityCheckerFixtrue, Legnth2xDiffTest2) {
	string str_A = "A";
	string str_B = "BLTABC";

	EXPECT_EQ(0, similarityChecker.checkLength(str_A, str_B));
}

TEST_F(SimilarityCheckerFixtrue, LegnthSimilarityTest1) {
	string str_A = "ABCD";
	string str_B = "BLTABC";

	EXPECT_EQ(30, similarityChecker.checkLength(str_A, str_B));
}

TEST_F(SimilarityCheckerFixtrue, LegnthSimilarityTest2) {
	string str_A = "AAABB";
	string str_B = "BAA";

	EXPECT_EQ(20, similarityChecker.checkLength(str_A, str_B));
}

TEST_F(SimilarityCheckerFixtrue, LegnthSimilarityTest3) {
	string str_A = "AA";
	string str_B = "AAE";

	EXPECT_EQ(30, similarityChecker.checkLength(str_A, str_B));
}

TEST_F(SimilarityCheckerFixtrue, AlphabetSameTest1) {
	string str_A = "ABC";
	string str_B = "ABC";

	EXPECT_EQ(40, similarityChecker.checkAlphabet(str_A, str_B));
}

TEST_F(SimilarityCheckerFixtrue, AlphabetSameTest2) {
	string str_A = "ABC";
	string str_B = "CAB";

	EXPECT_EQ(40, similarityChecker.checkAlphabet(str_A, str_B));
}

TEST_F(SimilarityCheckerFixtrue, AlphabetSameTest3) {
	string str_A = "ABC";
	string str_B = "CABA";

	EXPECT_EQ(40, similarityChecker.checkAlphabet(str_A, str_B));
}

TEST_F(SimilarityCheckerFixtrue, AlphabetTotallyDiffTest1) {
	string str_A = "ABC";
	string str_B = "DEF";

	EXPECT_EQ(0, similarityChecker.checkAlphabet(str_A, str_B));
}

TEST_F(SimilarityCheckerFixtrue, AlphabetTotallyDiffTest2) {
	string str_A = "ABC";
	string str_B = "ZZZZZZ";

	EXPECT_EQ(0, similarityChecker.checkAlphabet(str_A, str_B));
}

TEST_F(SimilarityCheckerFixtrue, AlphabetDiffTest1) {
	string str_A = "ABC";
	string str_B = "ABD";

	EXPECT_EQ(20, similarityChecker.checkAlphabet(str_A, str_B));
}

TEST_F(SimilarityCheckerFixtrue, AlphabetDiffTest2) {
	string str_A = "ABC";
	string str_B = "BBBB";

	EXPECT_EQ(13, similarityChecker.checkAlphabet(str_A, str_B));
}

TEST_F(SimilarityCheckerFixtrue, AlphabetDiffTest3) {
	string str_A = "AAAAABBBB";
	string str_B = "AZC";

	EXPECT_EQ(10, similarityChecker.checkAlphabet(str_A, str_B));
}

