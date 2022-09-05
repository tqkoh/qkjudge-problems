#include "bits/stdc++.h"
using namespace std;
#define all(v) v.begin(), v.end()

const int MAX = 202020;
const int MOD = 998244353;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++){
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k){
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
	COMinit();
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i<n; ++i)cin >> a[i];
	sort(all(a));

	int ans = 0, ncr = 1;
	for(int i = k-1; i<n; ++i){
		ans += COM(i, k-1)*a[i] % MOD, ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
