#!/usr/bin/env pypy

import bisect
import sys


def input():
    return sys.stdin.readline()[:-1]


n, m = map(int, input().split())
a = list(map(int, input().split()))
q = int(input())
b = list(map(int, input().split()))

s = set()
g = []
for i in range(n - 1, -1, -1):
    if a[i] not in s:
        s.add(a[i])
        g.append(a[i])
g.reverse()
g_sorted = sorted(g)


def fulfill(i, l):
    used = bisect.bisect_right(g_sorted, l)
    return l - used >= i


def f(i):
    i += 1
    ok = int(1e18 + 1)
    ng = 0
    cen = 0
    while abs(ok - ng) > 1:
        cen = (ok + ng) // 2
        if fulfill(i, cen):
            ok = cen
        else:
            ng = cen
    return ok


for i in range(q):
    b[i] -= 1
    if b[i] < n:
        print(a[b[i]])
        continue
    b[i] -= n
    b[i] %= m
    if b[i] < m - len(g):
        print(f(b[i]))
    else:
        b[i] -= m - len(g)
        print(g[b[i]])
