import sys
from bisect import bisect
input = sys.stdin.readline

N, M = map(int, input().split())
A = list(map(int, input().split()))
sA = sorted(set(A))
for i in range(len(sA)):
    sA[i] -= i + 1
dA = {}
for a in A:
    if a in dA:
        dA.pop(a)
    dA[a] = None
dA = list(dA)
Q = int(input())
B = list(map(int, input().split()))
for b in B:
    b -= 1
    if b < N:
        print(A[b])
        continue
    b -= N
    b %= M
    if b >= M - len(dA):
        print(dA[b - M])
        continue
    print(b + 1 + bisect(sA, b))
