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
	vector<int> K;
	vector<vector<int>> C;
	int Q;
	vector<int> q;
	vector<long long> sum;

	void InputFormat() {
		LINE(N);
		LINES(K, C) % SIZE(N);
		LINE(Q);
		LINES(q) % SIZE(Q);
	}

	void OutputFormat() {
		LINES(sum) % SIZE(Q);
	}

	void GradingConfig() {
		TimeLimit(2);
	}

	void Constraints() {
		CONS(1 <= N && N <= 100000);
		CONS(eachElementBetween(K, 1, 100000));
		CONS(allInside(C, 1, 1000000000));
		CONS(totalBetween(K, 1, 100000));
		CONS(1 <= Q && Q <= 100000);
		CONS(eachElementBetween(q, 1, N));
	}

	bool allInside(vector<vector<int>>& C, int lo, int hi) {
		for (vector<int>& it : C) {
			if (!eachElementBetween(it, lo, hi)) {
				return false;
			}
		}
		return true;
	}

	bool totalBetween(vector<int>& K, int lo, int hi) {
		int sum = 0;
		for (int& it : K) {
			sum += it;
		}
		return lo <= sum && sum <= hi;
	}

	bool eachElementBetween(const vector<int>& v, int lo, int hi) {
		for (int x : v) {
			if (x < lo || x > hi) {
				return false;
			}
		}
		return true;
	}

	bool eachElementGreaterAndLessThan(const vector<int>& a, const vector<int>& b, int hi) {
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] < b[i] || a[i] > hi) {
				return false;
			}
		}
		return true;
	}
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
	void BeforeTestCase() {
		K.clear(), C.clear(), q.clear(), sum.clear();
	}

	void SampleTestCase1() {
		Input({
			"5",
			"4 1 2 3 4",
			"3 10 9 8",
			"1 2000",
			"1 14",
			"2 1 1",
			"3",
			"5",
			"2",
			"3"
		});
		Output({
			"2",
			"27",
			"2000"
		});
	}

	void SampleTestCase2() {
		Input({
			"2",
			"2 10 9",
			"1 1000000000",
			"2",
			"2",
			"1"
		});
		Output({
			"1000000000",
			"19"
		});
	}

	void TestCases() {
		CASE(
			N = rnd.nextInt(1,10),
			randomWeight(N, K, 1, 10),
			randomWeightWithDependant(K, C, 1, 10),
			Q = N;
			tanyaSemuaUrut(Q, q, N));
		CASE(
			N = rnd.nextInt(1,10),
			randomWeight(N, K, 1, 10),
			randomWeightWithDependant(K, C, 1, 10),
			Q = N;
			tanyaSemuaUrut(Q, q, N));
		CASE(
			N = rnd.nextInt(1,100),
			randomWeight(N, K, 1, 100),
			randomWeightWithDependant(K, C, 1, 100),
			Q = N;
			tanyaSemuaAcak(Q, q, N));
		CASE(
			N = rnd.nextInt(1,1000),
			randomWeight(N, K, 1, MAX_VAL/N),
			randomWeightWithDependant(K, C, 1, 1000),
			Q = N;
			tanyaSemuaUrut(Q, q, N));
		CASE(
			N = rnd.nextInt(1,1000),
			randomWeight(N, K, 1, MAX_VAL/N),
			randomWeightWithDependant(K, C, 1, 1000),
			Q = N;
			tanyaSemuaUrut(Q, q, N));
		CASE(
			N = rnd.nextInt(1,1000),
			randomWeight(N, K, 1, MAX_VAL/N),
			randomWeightWithDependant(K, C, 1, 1000),
			Q = N;
			tanyaSemuaUrut(Q, q, N));
		CASE(
			N = rnd.nextInt(1,10000),
			randomWeight(N, K, 1, MAX_VAL/N),
			randomWeightWithDependant(K, C, 1, 10000),
			Q = N;
			tanyaSemuaAcak(Q, q, N));
		CASE(
			N = rnd.nextInt(1,100000),
			randomWeight(N, K, 1, MAX_VAL/N),
			randomWeightWithDependant(K, C, 1, 100000),
			Q = N;
			tanyaSemuaUrut(Q, q, N));
		CASE(
			N = rnd.nextInt(1,100000),
			randomWeight(N, K, 1, MAX_VAL/N),
			randomWeightWithDependant(K, C, 1, 100000),
			Q = N;
			tanyaSemuaAcak(Q, q, N));
		CASE(
			N = 100000,
			randomWeight(N, K, 1, MAX_VAL/N),
			randomWeightWithDependant(K, C, 1, 100000),
			Q = N;
			tanyaSemuaUrut(Q, q, N));
		CASE(
			N = 100000,
			randomWeight(N, K, 1, MAX_VAL/N),
			randomWeightWithDependant(K, C, 1, 100000),
			Q = N;
			tanyaSemuaAcak(Q, q, N));
		CASE(
			N = 100000,
			randomWeight(N, K, 1, MAX_VAL/N),
			randomWeightWithDependant(K, C, 1, 1000000000),
			Q = N;
			tanyaSemuaAcak(Q, q, N));
		CASE(
			N = 100000,
			randomWeight(N, K, 1, MAX_VAL/N),
			randomWeightWithDependant(K, C, 1, 1000000000),
			Q = N;
			tanyaSemuaAcak(Q, q, N));
		CASE(
			N = 100000,
			randomWeight(N, K, 1, MAX_VAL/N),
			randomWeightWithDependant(K, C, 1, 1000000000),
			Q = N;
			tanyaSemuaAcak(Q, q, N));
		CASE(
			N = 100000,
			randomWeight(N, K, 1, MAX_VAL/N),
			randomWeightWithDependant(K, C, 1, 1000000000),
			Q = N;
			tanyaSemuaAcak(Q, q, N));
		CASE(
			N = 100000,
			randomWeight(N, K, 1, MAX_VAL/N),
			randomWeightWithDependant(K, C, 1, 1000000000),
			Q = N;
			tanyaSemuaAcak(Q, q, N));
		CASE(
			N = 100000,
			randomWeight(N, K, 1, MAX_VAL/N),
			randomWeightWithDependant(K, C, 900000000, 1000000000),
			Q = N;
			tanyaSemuaAcak(Q, q, N));
		CASE(
			N = 100000,
			randomWeight(N, K, 1, MAX_VAL/N),
			randomWeightWithDependant(K, C, 900000000, 1000000000),
			Q = N;
			tanyaSemuaAcak(Q, q, N));

	}

	void randomWeightWithDependant(vector<int>& K, vector<vector<int>>& C, int minW = 1, int maxW = 10) {
		C.resize(K.size());
		for (int i = 0; i < K.size(); ++i) {
			randomWeight(K[i], C[i], minW, maxW);
		}
	}

	void randomWeight(int m, vector<int>& w, int minW = 1, int maxW = 10) {
		w.resize(m);
		for (int i = 0; i < m; i++) {
			w[i] = rnd.nextInt(minW, maxW);
		}
	}

	void tanyaSemuaUrut(int m, vector<int>& x, int maxW) {
		tanyaSemua(m, x, maxW, false);
	}

	void tanyaSemuaAcak(int m, vector<int>& x, int maxW) {
		tanyaSemua(m, x, maxW, true);
	}

	void tanyaSemua(int m, vector<int>& x, int maxW, bool acak) {
		x.resize(m);
		for (int i = 0; i < maxW; ++i) {
			x[i] = i+1;
		}
		for (int i = maxW; i < m; ++i) {
			x[i] = rnd.nextInt(1, maxW);
		}
		if (acak) {
			mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
			shuffle(x.begin(), x.end(), rng);
		}
	}
};