#include "bits/stdc++.h"
using namespace std;
#define all(v) v.begin(), v.end()

int main(){
	const int MAX_A_I = 1e6+10;
	int n;
	cin >> n;
	vector<int> a(n), cur(MAX_A_I, 1<<30);
	for(int i=0; i<n; ++i)cin >> a[i];

	long long ans = 0;
	for(int i = MAX_A_I-1; i>0; --i){
		for(int j = i; j<MAX_A_I; j += i){
			cur[j] = i;
		}
		if(i<=n)ans += cur[a[i-1]];
	}
	cout << ans << endl;
	return 0;
}
