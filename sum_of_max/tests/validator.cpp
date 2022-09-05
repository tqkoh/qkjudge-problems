#include <bits/stdc++.h>
#include "constraints.hpp"
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	int N = inf.readInt(MIN_N, MAX_N, "N");
	inf.readSpace();
	int K = inf.readInt(MIN_K, N, "K");
	inf.readEoln();
	for(int i = 0; i < N; ++i) {
		inf.readInt(MIN_A_I, MAX_A_I, format("A_%d", i + 1));
		if(i < N - 1) {
			inf.readSpace();
		}
	}
	inf.readEoln();
	inf.readEof();
	return 0;
}
