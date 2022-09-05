#include "bits/stdc++.h"
using namespace std;

class UnionFind{
public:
	vector<int> par, rank, hon; // hon: 正直者の数
	UnionFind(int n){ init(n); }
	void init(int n){
		par.resize(2*n), rank.resize(2*n), hon.resize(2*n);
		for(int i=0; i<2*n; ++i)par[i] = i, hon[i] = i%2; // 正直者 1 人のみのグループが 1
	}
	int root(int x){ return x==par[x]?x:par[x]=root(par[x]); }
	bool same(int x, int y){ return root(x)==root(y); }
	void unite(int x, int y){
		x = root(x), y = root(y);
		if(x==y)return;
		if(rank[x]<rank[y]){
			par[x] = y;
			hon[y] += hon[x];
		} else{
			par[y] = x;
			hon[x] += hon[y];
			if(rank[x]==rank[y])++rank[x];
		}
	}
};

int main(){
	int n, a, b, ans = 0;
	cin >> n;
	UnionFind t(n);
	for(int i=0; i<n; ++i){
		cin>>a>>b;
		t.unite(2*i+1, 2*a+b); // b==1のとき正と正、b==0のとき正と嘘をつなぐ
		t.unite(2*i, 2*a+1-b); // b==1のとき嘘と嘘、b==0のとき嘘と正をつなぐ
	}
	for(int i=0; i<n; ++i){
		if(!t.same(2*i, 2*i+1)){ // 矛盾が起きていないなら、正直者が多くなるほうを選び答えに足す
			ans += max(t.hon[t.root(2*i)], t.hon[t.root(2*i+1)]);
		}
		t.hon[t.root(2*i)] = t.hon[t.root(2*i+1)] = 0; // 1 回見たらグループの正直者の数を 0 にすればダブルカウントしない
	}
	cout << ans << endl;
}