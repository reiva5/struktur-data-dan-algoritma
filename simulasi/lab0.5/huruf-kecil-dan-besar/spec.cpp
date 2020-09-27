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
	string S, ans;

	void InputFormat() {
		LINE(S);
	}

	void OutputFormat() {
		LINE(ans);
	}

	void GradingConfig() {
		TimeLimit(1);
	}

	void Constraints() {
		CONS(1 <= S.size() && S.size() <= 100);
	}
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
	void BeforeTestCase() {
		S = "", ans = "";
	}

	void SampleTestCase1() {
		Input({
			"namron"
		});
		Output({
			"nAmRoN"
		});
	}

	void SampleTestCase2() {
		Input({
			"namronYANGkeren"
		});
		Output({
			"nAmRoNyAnGkErEn"
		});
	}

	void TestCases() {
		CASE(generateRandomString(rnd.nextInt(1,10), S, true, true));
		CASE(generateRandomString(rnd.nextInt(1,10), S, true, false));
		CASE(generateRandomString(rnd.nextInt(1,10), S, false, true));
		CASE(generateRandomString(rnd.nextInt(1,10), S, true, true));
		CASE(generateRandomString(rnd.nextInt(1,10), S, true, false));
		CASE(generateRandomString(rnd.nextInt(1,10), S, false, true));
		CASE(generateRandomString(rnd.nextInt(10,100), S, true, true));
		CASE(generateRandomString(rnd.nextInt(10,100), S, true, false));
		CASE(generateRandomString(rnd.nextInt(10,100), S, false, true));
		CASE(generateRandomString(rnd.nextInt(10,100), S, true, true));
		CASE(generateRandomString(rnd.nextInt(10,100), S, true, false));
		CASE(generateRandomString(rnd.nextInt(10,100), S, false, true));
		CASE(generateRandomString(100, S, true, true));
		CASE(generateRandomString(100, S, true, false));
		CASE(generateRandomString(100, S, false, true));
		CASE(generateRandomString(100, S, true, true));
		CASE(generateRandomString(100, S, true, false));
		CASE(generateRandomString(100, S, false, true));
	}

	void generateRandomString(int sz, string& s, bool anyUpperCase, bool anyLowerCase) {
		s.resize(sz);
		if (anyUpperCase && anyLowerCase) {
			for (int i = 0; i < sz; ++i) {
				s[i] = rnd.nextInt(0,1) ? rnd.nextInt('a', 'z') : rnd.nextInt('A', 'Z');
			}
		} else if (anyUpperCase) {
			for (int i = 0; i < sz; ++i) {
				s[i] = rnd.nextInt('A', 'Z');
			}
		} else {
			for (int i = 0; i < sz; ++i) {
				s[i] = rnd.nextInt('a', 'z');
			}
		}
	}
};