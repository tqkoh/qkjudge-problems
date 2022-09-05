#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	cin >> n;
	long long ans = 0;
	for(int i = 1; i<n+1; ++i){
		int a, prev_r = 1<<30, done = 0;
		cin>>a;
		for(int j=1; j*j<=a; ++j)if(a%j==0){
			if(i<=j){ ans += j, done = 1; break; }
			const int r=a/j;
			if(r<i){ ans += prev_r, done = 1; break; }
			prev_r = r;
		}
		if(!done)ans += prev_r;
	}
	cout << ans << endl;
	return 0;
}
