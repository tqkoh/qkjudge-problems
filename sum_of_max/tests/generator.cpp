#include <bits/stdc++.h>
#include "constraints.hpp"
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	rnd.setSeed(79000);
	// random
	auto random = [&](int test_num, string name, int min_n = MIN_N,
					  int max_n = MAX_N, int min_k = MIN_K,
					  int min_a_i = MIN_A_I, int max_a_i = MAX_A_I) -> void {
		for(int t = 0; t < test_num; ++t) {
			ofstream fout(format(name, t).c_str());
			int N = rnd.next(min_n, max_n);
			fout << N << " " << rnd.next(min_k, N) << endl;
			for(int i = 0; i < N; ++i) {
				fout << rnd.next(min_a_i, max_a_i);
				if(i < N - 1) {
					fout << " ";
				}
			}
			fout << endl;
			fout.close();
		}
	};
	// small
	random(2, "01_small_\%02d.in", MIN_N, MIN_N + 20, MIN_K, 1, 100000);
	// random
	random(10, "02_random_\%02d.in");
	// max
	random(3, "03_max_\%02d.in", MAX_N - 1, MAX_N, MAX_N / 2, MAX_N / 2);
	random(1, "03_max_03.in", MAX_N, MAX_N, MAX_N / 2, MAX_N / 2, 998244353);
	// hand
	return 0;
}
