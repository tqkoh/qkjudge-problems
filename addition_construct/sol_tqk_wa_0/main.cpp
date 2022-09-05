#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	int a = min(N, 100);
	int b = N - a;
	cout << a << " " << b << endl;
	return 0;
}
