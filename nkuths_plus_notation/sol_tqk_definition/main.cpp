#include "bits/stdc++.h"
using namespace std;
#define all(v) v.begin(), v.end()
using ll = int64_t;

int main(){
	ll n, a, b;
	cin >> n >> a >> b;
	auto f = [&](auto f, ll n, ll a, ll b)->ll{
		if(n==1)return a+b;
		ll res = a;
		for(int i = 0; i<b-1; ++i){
			res = f(f, n-1, a, res);
		}
		return res;
	};
	cout << f(f, n, a, b) << endl;
	return 0;
}
