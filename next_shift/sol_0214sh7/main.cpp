#include <bits/stdc++.h>
using namespace std;
#define MM <<" "<<

int main(void){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    
    long long N,M;
    cin >> N >> M;
    vector<long long> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    long long Q;
    cin >> Q;
    vector<long long> B(Q);
    for(int i=0;i<Q;i++){
        cin >> B[i];
    }

    //最後に選ばれた日付を記録する
    map<long long,long long> Mp;
    for(int i=0;i<N;i++){
        Mp[A[i]] = i+1;
    }

    //選ばれた人数とその出席番号を記録
    vector<pair<long long,long long>> D;
    for(auto it = Mp.begin();it!=Mp.end();it++){
        D.push_back({it->second,it->first});
    }

    sort(D.begin(),D.end());
    vector<long long> E(D.size());
    for(int i=0;i<(int)(E.size());i++){
        E[i] = D[i].second;
    }
    sort(E.begin(),E.end());


    for(int i=0;i<Q;i++){
        long long q = B[i];

        if(q <= N){
            cout << A[q-1] << endl;
            continue;
        }

        q -= N+1;
        q %= M;

        if(q <= M-N){
            
            q += 1;
            long long ok = M,ng = 0,mid;

            while(abs(ok-ng)>1){

                mid = (ok+ng)/2;
                auto it = lower_bound(E.begin(),E.end(),mid+1);
                long long r = it-E.begin();
                //r = 除くべきものがいくつあるか

                if(q<=mid-r){
                    ok = mid;
                }else{
                    ng = mid;
                }

            }

            cout << ok << endl;
        }else{
            
            cout << D[q-M+N-1].second << endl;
        }

    }
    
    return 0;
}
	