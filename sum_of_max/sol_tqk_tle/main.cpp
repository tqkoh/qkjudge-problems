#include "bits/stdc++.h"
using namespace std;
#define all(v) v.begin(), v.end()

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i<n; ++i)cin >> a[i];
	sort(all(a));

	int ans = 0;
	auto f = [&](auto f, int i, int d)->void{
		if(d==k){
			ans += a[i];
			ans %= 998244353;
			return;
		}
		if(d>k)return;
		for(int j = i+1; j<n; ++j){
			f(f, j, d+1);
		}
	};
	for(int i = 0; i<n; ++i){
		f(f, i, 1);
	}
	cout << ans << endl;
	return 0;
}
