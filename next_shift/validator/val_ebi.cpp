#include "../../testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define all(a) begin(a), end(a)
#define space inf.readChar(' ')
#define endl inf.readChar('\n')
#define eof inf.readEof()
tuple<ll> read(ll min, ll max){
    ll a = inf.readLong(min, max);
    endl;
    return tuple{a};
}
template<class... T> auto read(ll min, ll max, T... t){
    ll a = inf.readLong(min, max);
    space;
    return tuple_cat(tuple{a}, read(t...));
}
string read(string p){
    return inf.readLine(p);
}
vector<ll> reads(ll N, ll min, ll max){
    auto a = inf.readLongs(N, min, max);
    endl;
    return a;
}
vector<string> read_lines(ll N, string p){
    return inf.readLines(N, p);
}
template<class... T> auto read_lines(ll N, T... t){
    vector<decltype(read(t...))> a;
    a.reserve(N);
    while(N--) a.push_back(read(t...));
    return a;
}
vector<vector<ll>> read_matrix(ll H, ll W, ll min, ll max){
    vector<vector<ll>> ans(H);
    for(auto& v : ans) v = reads(W, min, max);
    return ans;
}

const int MIN_N = 1;
const int MAX_N = 100000;
const ll MIN_M = 1;
const ll MAX_M = 1000000000000000000;
const int MIN_Q = 1;
const int MAX_Q = 100000;
const ll MIN_B = 1;
const ll MAX_B = 1000000000000000000;

int main() {
    registerValidation();
    auto [N, M] = read(MIN_N, MAX_N, MIN_M, MAX_M);
    auto A = reads(N, 1, M);
    auto [Q] = read(MIN_Q, MAX_Q);
    auto B = reads(Q, MIN_B, MAX_B);
    eof;
}