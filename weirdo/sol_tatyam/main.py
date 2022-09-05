#!/usr/local/bin/pypy3
import sys
input = sys.stdin.readline
def root(i) -> int:
    while True:
        if uf[i] < 0:
            return i
        if uf[uf[i]] < 0:
            return uf[i]
        uf[i] = uf[uf[i]]
        i = uf[i]
def unite(i, j) -> None:
    i = root(i)
    j = root(j)
    if i == j:
        return
    if uf[i] > uf[j]:
        i, j = j, i
    uf[i] += uf[j]
    uf[j] = i
def same(i, j) -> bool:
    return root(i) == root(j)

N = int(input())
uf = [-1] * (N * 2)
for i in range(N):
    A, B = map(int, input().split())
    if B == 0:
        unite(i, A + N)
        unite(i + N, A)
    else:
        unite(i, A)
        unite(i + N, A + N)

cnt = [0] * (N * 2)
for i in range(N):
    cnt[root(i)] += 1

ans = 0
for i in range(N):
    if uf[i] < 0:
        i, j = root(i), root(i + N)
        if i != j:
            ans += max(cnt[i], cnt[j])
    if uf[i + N] < 0:
        i, j = root(i), root(i + N)
        if i != j:
            ans += max(cnt[i], cnt[j])

print(ans >> 1)
