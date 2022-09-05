#include <bits/stdc++.h>
#include "constraints.hpp"
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	rnd.setSeed(79000);
	// random
	auto random = [&](int test_num, string name, int min_n, int max_n) -> void {
		for(int t = 0; t < test_num; ++t) {
			ofstream fout(format(name, t).c_str());
			int N = rnd.next(min_n, max_n);
			fout << N << endl;
			for(int i = 0; i < N; ++i) {
				fout << rnd.next(i + 1, MAX_A_I);
				if(i < N - 1) {
					fout << " ";
				}
			}
			fout << endl;
			fout.close();
		}
	};
	// small
	random(2, "01_small_\%02d.in", MIN_N, MIN_N + 100);
	// random
	random(11, "02_random_\%02d.in", MIN_N, MAX_N);
	// max
	random(3, "03_max_\%02d.in", MAX_N - 3, MAX_N);
	// hand
	{
		ofstream fout("04_hand_00.in");
		int N = MAX_N;
		fout << N << endl;
		for(int i = 0; i < N; ++i) {
			fout << max(997920, i + 1);
			if(i < N - 1) {
				fout << " ";
			}
		}
		fout << endl;
		fout.close();
	}
	{
		ofstream fout("04_hand_01.in");
		int N = MAX_N;
		fout << N << endl;
		for(int i = 0; i < N; ++i) {
			fout << max(999979, i + 1);
			if(i < N - 1) {
				fout << " ";
			}
		}
		fout << endl;
		fout.close();
	}
	{
		ofstream fout("04_hand_02.in");
		int N = MAX_N;
		fout << N << endl;
		for(int i = 0; i < N; ++i) {
			fout << max(999983, i + 1);
			if(i < N - 1) {
				fout << " ";
			}
		}
		fout << endl;
		fout.close();
	}
	{
		ofstream fout("04_hand_03.in");
		int N = MAX_N;
		fout << N << endl;
		vector<int> prime(N, 1);
		for(int p = 2; p < N; ++p) {
			if(prime[p]) {
				for(int k = 1; k * p < N; ++k) {
					prime[k * p] = 0;
				}
			}
		}
		int c = MAX_A_I, cur_p = 999983;
		vector<int> ans(N);
		for(int i = N - 1; i >= 0; --i) {
			if(i + 1 <= c) {
				cur_p = c;
				while(!prime[--c])
					;
			}
			ans[i] = cur_p;
		}
		for(int i = 0; i < N; ++i) {
			fout << max(ans[i], i + 1);
			if(i < N - 1) {
				fout << " ";
			}
		}
		fout << endl;
		fout.close();
	}
	return 0;
}
