#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;

long long inverse(long long b){
    /*
    Copyright (c) 2021 0214sh7
    https://github.com/0214sh7/library/
    */
    long long r=1,e=MOD-2;
    while(e){
        if(e&1){
            r=(r*b)%MOD;
        }
        b=(b*b)%MOD;
        e >>=1;
    }
    return r;
}

int main(void){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    
    long long N,K;
    cin >> N >> K;
    vector<long long> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());

    vector<long long> fact(N+1,1),factinv(N+1,1);
    for(int i=0;i<N;i++){
        fact[i+1] = (fact[i]*(i+1))%MOD;
    }
    factinv[N] = inverse(fact[N]);
    for(int i=N-1;i>=0;i--){
        factinv[i] = (factinv[i+1]*(i+1))%MOD;
    }

    long long Ans = 0;
    for(int i=N-1;i>=K-1;i--){
        //binom(i,K-1)
        long long r = fact[i];
        r = (r*factinv[K-1])%MOD;
        r = (r*factinv[i-K+1])%MOD;

        r = (r * A[i])%MOD;
        Ans = (Ans+r)%MOD;
    }

    cout << Ans << endl;
        
    return 0;
}
	