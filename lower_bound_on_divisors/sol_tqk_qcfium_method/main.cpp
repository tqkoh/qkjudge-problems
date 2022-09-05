#include "bits/stdc++.h"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	cin >> n;
	long long ans = 0;
	for(int i = 1; i<n+1; ++i){
		int a, prev_r = 1<<30, done = 0;
		cin>>a;
		for(int j=1; j*j<=a; ++j){
			const int r=a/j;
			if(a-j*r==0){
				if(i<=j){ ans += j, done = 1; break; }
				if(r<i){ ans += prev_r, done = 1; break; }
				prev_r = r;
			}
		}
		if(!done)ans += prev_r;
	}
	cout << ans << endl;
	return 0;
}
