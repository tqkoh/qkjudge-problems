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
				fout << rnd.next(MIN_A_I, N - 1) << " "
					 << rnd.next(MIN_B_I, MAX_B_I) << endl;
			}
			fout.close();
		}
	};
	// small
	random(14, "01_small_\%02d.in", MIN_N, SMALL_N);
	// medium
	random(3, "02_medium_\%02d.in", SMALL_N, LARGE_N);
	// large
	random(3, "03_large_\%02d.in", LARGE_N, MAX_N);
	// max
	random(5, "04_max_\%02d.in", MAX_N - 2, MAX_N);
	// hand
	{
		ofstream fout("05_hand_00.in");
		int N = MAX_N;
		fout << N << endl;
		for(int i = 0; i < N; ++i) {
			fout << (i + 1) % N << " " << (i != N - 1) << endl;
		}
		fout.close();
	}
	{
		ofstream fout("05_hand_01.in");
		int N = MAX_N;
		fout << N << endl;
		for(int i = 0; i < N; ++i) {
			fout << (i + N - 1) % N << " " << 0 << endl;
		}
		fout.close();
	}
	{
		ofstream fout("05_hand_02.in");
		int N = MAX_N - 1;
		fout << N << endl;
		for(int i = 0; i < N; ++i) {
			fout << (i + N / 2) % N << " " << 1 << endl;
		}
		fout.close();
	}
	return 0;
}
