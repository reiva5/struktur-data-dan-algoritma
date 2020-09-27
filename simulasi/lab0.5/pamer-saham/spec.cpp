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
	int N;
	vector<int> a;
	long long sum;

	void InputFormat() {
		LINE(N);
		LINE(a % SIZE(N));
	}

	void OutputFormat() {
		LINE(sum);
	}

	void GradingConfig() {
		TimeLimit(2);
	}

	void Constraints() {
		CONS(1 <= N && N <= 1000000);
		CONS(eachElementBetween(a, -1000000000, 1000000000));
	}

	bool eachElementBetween(const vector<int>& v, int lo, int hi) {
		for (int x : v) {
			if (x < lo || x > hi) {
				return false;
			}
		}
		return true;
	}
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
	void BeforeTestCase() {
		a.clear();
	}

	void SampleTestCase1() {
		Input({
			"5",
			"1 2 3 4 5"
		});
		Output({
			"15"
		});
	}

	void SampleTestCase2() {
		Input({
			"5",
			"1 2 -1000 3 4"
		});
		Output({
			"7"
		});
	}

	void SampleTestCase3() {
		Input({
			"5",
			"300 -200 150 -200 500"
		});
		Output({
			"550"
		});
	}

	void SampleTestCase4() {
		Input({
			"5",
			"-100 -200 1000 -300 -400"
		});
		Output({
			"1000"
		});
	}

	void SampleTestCase5() {
		Input({
			"3",
			"-100 -200 -300"
		});
		Output({
			"0"
		});
	}

	void TestCases() {
		CASE(
			N = rnd.nextInt(1,10),
			randomWeight(N, a, 1, 100));
		CASE(
			N = rnd.nextInt(1,10),
			randomWeight(N, a, 1, 100));
		CASE(
			N = rnd.nextInt(1,10),
			randomWeight(N, a, -100, 100));
		CASE(
			N = rnd.nextInt(1,10),
			randomWeight(N, a, -100, 100));
		CASE(
			N = rnd.nextInt(100,1000),
			randomWeight(N, a, 1, 10000));
		CASE(
			N = rnd.nextInt(100,1000),
			randomWeight(N, a, 1, 10000));
		CASE(
			N = rnd.nextInt(100,1000),
			randomWeight(N, a, -10000, 10000));
		CASE(
			N = rnd.nextInt(100,1000),
			randomWeight(N, a, -10000, 10000));
		CASE(
			N = rnd.nextInt(10000,100000),
			randomWeight(N, a, -1000000000, 1000000000));
		CASE(
			N = rnd.nextInt(10000,100000),
			randomWeight(N, a, -1000000000, 1000000000));
		CASE(
			N = rnd.nextInt(10000,100000),
			randomWeight(N, a, -1000000000, 1000000000));
		CASE(
			N = 1000000,
			randomWeight(N, a, 900000000, 1000000000));
		CASE(
			N = 1000000,
			randomWeight(N, a, -1000000000, 1000000000));
		CASE(
			N = 1000000,
			randomWeight(N, a, -1000000000, 1000000000));
		CASE(
			N = 1000000,
			randomWeight(N, a, -1000000000, 1000000000));
	}

	void randomWeight(int m, vector<int>& w, int minW = -10, int maxW = 10) {
		w.resize(m);
		for (int i = 0; i < m; i++) {
			w[i] = rnd.nextInt(minW, maxW);
		}
	}
};