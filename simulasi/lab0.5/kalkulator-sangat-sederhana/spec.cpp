#include <tcframe/spec.hpp>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace tcframe;
using namespace std;

const int MAX_VAL = 1e5;

class ProblemSpec : public BaseProblemSpec {
protected:
	int Q;
	vector<char> c;
	vector<string> a, b;
	vector<string> ans;

	void InputFormat() {
		LINE(Q);
		LINES(c, a, b) % SIZE(Q);
	}

	void OutputFormat() {
		LINES(ans) % SIZE(Q);
	}

	void GradingConfig() {
		TimeLimit(2);
	}

	void Constraints() {
		CONS(1 <= Q && Q <= 10000);
		CONS(eachElementIn(c, {'+', '-', '*'}));
		CONS(eachElementSizeBetween(a, 1, 200));
		CONS(eachElementSizeBetween(b, 1, 200));
	}

	bool eachElementIn(vector<char>& c, set<char> operators) {
		for (char& cc : c) {
			if (operators.find(cc) == operators.end()) {
				return false;
			}
		}
		return true;
	}

	bool eachElementSizeBetween(vector<string>& arr, int minW = 1, int maxW = 10) {
		for (string& s : arr) {
			if (s.size() < minW || s.size() > maxW) {
				return false;
			}
		}
		return true;
	}
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
	void BeforeTestCase() {
		c.clear(), a.clear(), b.clear(), ans.clear();
	}

	void SampleTestCase1() {
		Input({
			"3",
			"+ 1 1",
			"* 2000000 0",
			"- 3 7"
		});
		Output({
			"2",
			"0",
			"-4"
		});
	}

	void SampleTestCase2() {
		Input({
			"3",
			"* 1000000000000000000000000 1000000000000000000000000",
			"- 1000000000000000000000000 1000000000000000000000000",
			"+ 1000000000000000000000000 1000000000000000000000000"
		});
		Output({
			"1000000000000000000000000000000000000000000000000",
			"0",
			"2000000000000000000000000"
		});
	}

	void TestCases() {
		CASE(
			Q = rnd.nextInt(1, 10),
			randomChar(Q, c),
			randomStringNumber(Q, a, 1, 5),
			randomStringNumber(Q, b, 1, 5));
		CASE(
			Q = rnd.nextInt(1, 10),
			randomChar(Q, c),
			randomStringNumber(Q, a, 1, 5),
			randomStringNumber(Q, b, 1, 5));
		CASE(
			Q = rnd.nextInt(1, 10),
			randomChar(Q, c),
			randomStringNumber(Q, a, 1, 5),
			randomStringNumber(Q, b, 1, 5));
		CASE(
			Q = rnd.nextInt(1, 100),
			randomChar(Q, c),
			randomStringNumber(Q, a, 1, 9),
			randomStringNumber(Q, b, 1, 9));
		CASE(
			Q = rnd.nextInt(1, 100),
			randomChar(Q, c),
			randomStringNumber(Q, a, 1, 9),
			randomStringNumber(Q, b, 1, 9));
		CASE(
			Q = rnd.nextInt(1, 100),
			randomChar(Q, c),
			randomStringNumber(Q, a, 1, 9),
			randomStringNumber(Q, b, 1, 9));
		CASE(
			Q = rnd.nextInt(1, 1000),
			randomChar(Q, c),
			randomStringNumber(Q, a, 1, 10),
			randomStringNumber(Q, b, 1, 10));
		CASE(
			Q = rnd.nextInt(1, 1000),
			randomChar(Q, c),
			randomStringNumber(Q, a, 1, 10),
			randomStringNumber(Q, b, 1, 10));
		CASE(
			Q = rnd.nextInt(1, 1000),
			randomChar(Q, c),
			randomStringNumber(Q, a, 1, 10),
			randomStringNumber(Q, b, 1, 10));
		CASE(
			Q = rnd.nextInt(1, 10000),
			randomChar(Q, c),
			randomStringNumber(Q, a, 1, 100),
			randomStringNumber(Q, b, 1, 100));
		CASE(
			Q = 10000,
			allSame(Q, c),
			randomStringNumber(Q, a, 1, 100),
			randomStringNumber(Q, b, 1, 100));
		CASE(
			Q = 10000,
			allSame(Q, c),
			randomStringNumber(Q, a, 1, 100),
			randomStringNumber(Q, b, 1, 100));
		CASE(
			Q = 10000,
			randomChar(Q, c),
			randomStringNumber(Q, a, 200, 200),
			randomStringNumber(Q, b, 200, 200));
		CASE(
			Q = 10000,
			randomChar(Q, c),
			randomStringNumber(Q, a, 200, 200),
			randomStringNumber(Q, b, 200, 200));
		CASE(
			Q = 10000,
			randomChar(Q, c),
			randomStringNumber(Q, a, 200, 200),
			randomStringNumber(Q, b, 200, 200));
		CASE(
			Q = 10000,
			allSame(Q, c),
			randomStringNumber(Q, a, 200, 200),
			randomStringNumber(Q, b, 200, 200));
		CASE(
			Q = 10000,
			allSame(Q, c),
			randomStringNumber(Q, a, 200, 200),
			randomStringNumber(Q, b, 200, 200));
		CASE(
			Q = 10000,
			allSame(Q, c),
			randomStringNumber(Q, a, 200, 200),
			randomStringNumber(Q, b, 200, 200));
	}

	void randomChar(int sz, vector<char>& c) {
		c.resize(sz);
		for (int i = 0; i < sz; ++i) {
			c[i] = "+-*"[rnd.nextInt(0,2)];
		}
	}

	void allSame(int sz, vector<char>& c, char def = '*') {
		c.resize(sz);
		for (int i = 0; i < sz; ++i) {
			c[i] = def;
		}
	}

	string generateRandomStringNumber(int minW = 1, int maxW = 5) {
		string res = "";
		int sz = rnd.nextInt(minW, maxW);
		if (sz == 1) {
			res.push_back('0' + rnd.nextInt(0,9));
		} else {
			res.push_back('0' + rnd.nextInt(1,9));
			--sz;
			while (sz--) {
				res.push_back('0' + rnd.nextInt(0,9));
			}
		}
		return res;
	}

	void randomStringNumber(int sz, vector<string>& arr, int minW = 1, int maxW = 5) {
		arr.resize(sz);
		for (int i = 0; i < sz; ++i) {
			arr[i] = generateRandomStringNumber(minW, maxW);
		}
	}
};