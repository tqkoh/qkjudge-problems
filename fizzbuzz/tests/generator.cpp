#include <bits/stdc++.h>
#include "constraints.hpp"
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	rnd.setSeed(79000);
	// random
	auto random = [&](int test_num, string name, int min_n = MIN_N) -> void {
		for(int t = 0; t < test_num; ++t) {
			ofstream fout(format(name, t).c_str());
			fout << rnd.next(min_n, MAX_N) << endl;
			fout.close();
		}
	};
	// small
	// random
	random(1, "01_random_\%02d.in");
	// max
	random(1, "02_max_\%02d.in", MAX_N);

	return 0;
}
