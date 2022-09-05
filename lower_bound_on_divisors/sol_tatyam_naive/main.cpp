#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int& a : A) cin >> a;
    int64_t ans = 0;
    for(int i = 0; i < N; i++){
        const int x = A[i];
        ans += [&]{
            for(int j = i + 1; j <= 1000; j++) if(x % j == 0) return j;
            for(int j = x / max(1000, i + 1); j; j--) if(x % j == 0) return x / j;
            abort();
        }();
    }
    cout << ans << endl;
}