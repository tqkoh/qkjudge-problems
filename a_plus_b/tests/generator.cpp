#include <bits/stdc++.h>
#include "constraints.hpp"
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	rnd.setSeed(79000);
	// random
	auto random = [&](int test_num, string name) -> void {
		for(int t = 0; t < test_num; ++t) {
			ofstream fout(format(name, t).c_str());
			fout << rnd.next(MIN_A, MAX_A) << " " << rnd.next(MIN_B, MAX_B)
				 << endl;
			fout.close();
		}
	};
	// small
	// random
	random(2, "01_random_\%02d.in");
	// max
	return 0;
}
