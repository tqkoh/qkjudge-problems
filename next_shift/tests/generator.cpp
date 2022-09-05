#include <bits/stdc++.h>
#include "constraints.hpp"
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	rnd.setSeed(79000);
	// random
	auto random = [&](int test_num, string name, ll min_n, ll max_n, ll min_m,
					  ll max_m, ll min_q, ll max_q, ll min_b_i,
					  ll max_b_i) -> void {
		for(int t = 0; t < test_num; ++t) {
			ofstream fout(format(name, t).c_str());
			ll N = rnd.next(min_n, max_n);
			ll M = rnd.next(min_m, max_m);
			fout << N << " " << M << endl;
			for(int i = 0; i < N; ++i) {
				fout << rnd.next(MIN_A_I, M) << " \n"[i == N-1];
			}
			ll Q = rnd.next(min_q, max_q);
			fout << Q << endl;
			for(int i = 0; i < Q; ++i) {
				fout << rnd.next(min_b_i, max_b_i) << " \n"[i == Q-1];
			}
			fout.close();
		}
	};
	// small
	random(2, "01_small_\%02d.in", MIN_N, MIN_N + 100, MIN_M,
		   MIN_M + (1ll << 30), MIN_Q, MIN_Q + 100, MIN_B_I, MIN_B_I + 200000);
	// random
	random(11, "02_random_\%02d.in", MIN_N, MAX_N, MIN_M, MAX_M, MIN_Q, MAX_Q,
		   MIN_B_I, MAX_B_I);
	// max
	random(3, "03_max_\%02d.in", MAX_N, MAX_N, MAX_M, MAX_M, MAX_Q, MAX_Q,
		   MAX_B_I / 2, MAX_B_I);
	// hand
	{
		ofstream fout("04_hand_00.in");
		ll N = MAX_N;
		ll M = MAX_M;
		fout << N << " " << M << endl;
		set<ll> s;
		for(int i = 0; i < N; ++i) {
			ll A_i = rnd.next(MIN_A_I, M);
			fout << A_i << " \n"[i == N-1];
			s.insert(A_i);
		}
		ll Q = MAX_Q;
		fout << Q << endl;
		for(int i = 0; i < Q; ++i) {
			fout << rnd.next(N + 1, N + 1 + M - ll(s.size())) << " \n"[i == Q-1];
		}
		fout.close();
	}
	return 0;
}
