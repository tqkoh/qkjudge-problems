#include <bits/stdc++.h>
#include "constraints.hpp"
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	rnd.setSeed(79000);
	// random
	auto random = [&](int test_num, string name, ll min_n, ll max_n, ll min_a,
					  ll max_a, ll min_b, ll max_b) -> void {
		for(int t = 0; t < test_num; ++t) {
			ofstream fout(format(name, t).c_str());
			ll N = rnd.next(min_n, max_n);
			ll A = rnd.next(min_a, max_a);
			ll B = rnd.next(min_b, max_b);
			fout << N << " " << A << " " << B << endl;
			fout.close();
		}
	};
	// small
	random(4, "01_small_\%02d.in", MIN_N, MIN_N + 1, MIN_A, MIN_A + 3, MIN_B,
		   MIN_B + 3);
	// random
	random(10, "02_random_\%02d.in", MIN_N, MAX_N, MIN_A, MAX_A, MIN_B, MAX_B);
	// max
	random(3, "03_max_\%02d.in", MAX_N, MAX_N, MAX_A - 2, MAX_A, MAX_B - 2,
		   MAX_B);
	// hand
	return 0;
}
