#include "bits/stdc++.h"
using namespace std;
#define all(v) v.begin(), v.end()
using ll = int64_t;

int main(){
	ll n, a, b;
	cin >> n >> a >> b;
	if(n==1){
		cout << a+b << endl;
	}
	else if(n==2){
		cout << a*b << endl;
	}
	else{
		cout << pow(a, b) << endl;
	}
	return 0;
}
