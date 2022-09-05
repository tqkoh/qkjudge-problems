#include <bits/stdc++.h>
#include "constraints.hpp"
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	int N = inf.readInt(MIN_N, MAX_N, "N");
	inf.readChar('\n');
	for(int i = 0; i < N; ++i) {
		inf.readInt(MIN_A_I, N - 1, format("A_%d", i));
		inf.readSpace();
		inf.readInt(MIN_B_I, MAX_B_I, format("B_%d", i));
		inf.readChar('\n');
	}
	inf.readEof();
	return 0;
}
