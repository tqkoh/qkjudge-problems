MOD = 998244353
N, K = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
ans = A[K - 1]
inv = 1
fac = 1
for i in range(K, N):
    fac *= i
    fac %= MOD
    ans *= i - K + 1
    ans %= MOD
    inv *= i - K + 1
    inv %= MOD
    ans += fac * A[i]
print(ans * pow(inv, MOD - 2, MOD) % MOD)
