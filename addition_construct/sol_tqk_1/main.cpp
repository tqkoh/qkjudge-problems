#include "bits/stdc++.h"
using namespace std;

int main(){
	int N;
	cin >> N;
	for(int a = 1; a<=5000; ++a){
		for(int b = 1; b<=5000; ++b){
			if(a+b==N){
				cout << a << " " << b << endl;
				return 0;
			}
		}
	}
	return 0;
}
