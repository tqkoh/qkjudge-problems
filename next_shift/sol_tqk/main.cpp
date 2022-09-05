#include "bits/stdc++.h"
using namespace std;
#define all(v) v.begin(), v.end()
using ll = int64_t;

int main(){
	ll n, m, q;
	cin >> n >> m;
	vector<ll> a(n), g;
	for(int i = 0; i<n; ++i)cin >> a[i];
	cin >> q;

	{
		set<ll>s;
		for(int i = n-1; i>=0; --i){
			if(!s.count(a[i])){
				s.insert(a[i]);
				g.push_back(a[i]);
			}
		}
		reverse(all(g));
	}
	vector g_sorted = g;
	sort(all(g_sorted));

	auto fulfill = [&](ll i, ll l)->bool{
		ll used = upper_bound(all(g_sorted), l)-g_sorted.begin();
		return l-used>=i;
	};
	auto f = [&](ll i)->ll{
		++i;
		ll ok = 1e18+1, ng = 0, cen;
		while(abs(ok-ng)>1)cen = (ok+ng)/2, (fulfill(i, cen)?ok:ng) = cen;
		return ok;
	};

	while(q--){
		ll b; // b_i
		cin >> b;
		--b;
		if(b<n){
			cout << a[b] << endl;
			continue;
		}
		b -= n;
		b %= m;
		if(b<m-g.size()){
			cout << f(b) << endl;
		}
		else{
			b -= m-g.size();
			cout << g[b] << endl;
		}
	}
	return 0;
}
