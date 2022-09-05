#include <bits/stdc++.h>
#include "constraints.hpp"
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	rnd.setSeed(79000);
	// random
	auto random = [&](int test_num, string name, int min_n = MIN_N,
					  int max_n = MAX_N) -> void {
		for(int t = 0; t < test_num; ++t) {
			ofstream fout(format(name, t).c_str());
			fout << rnd.next(min_n, max_n) << endl;
			fout.close();
		}
	};
	// small
	// random
	random(9, "01_small_\%02d.in", MIN_N, MAX_N);
	// max
	// hand
	random(1, "02_hand_00.in", 2, 2);
	return 0;
}
