#include <bits/stdc++.h>
#include "constraints.hpp"
#include "testlib.h"
using namespace std;
using ull = unsigned long long;

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	ll N = inf.readLong(ull(MIN_N), ull(MAX_N), "N");
	inf.readSpace();
	ll M = inf.readLong(ull(MIN_M), ull(MAX_M), "M");
	inf.readEoln();
	for(int i = 0; i < N; ++i) {
		inf.readLong(ull(MIN_A_I), ull(M), format("A_%d", i + 1));
		if(i < N - 1)
			inf.readSpace();
	}
	inf.readEoln();
	ll Q = inf.readLong(ull(MIN_Q), ull(MAX_Q), "Q");
	inf.readEoln();
	for(int i = 0; i < Q; ++i) {
		inf.readLong(ull(MIN_B_I), ull(MAX_B_I), format("B_%d", i + 1));
		if(i < Q - 1)
			inf.readSpace();
	}
	inf.readEoln();
	inf.readEof();
	return 0;
}
