#!/usr/bin/env pypy

import sys


def input():
    return sys.stdin.readline()[:-1]


MAX_A_I = 1000010
n = int(input())
a = list(map(int, input().split()))

ans = 0
cur = [1 << 30] * MAX_A_I
cnt = 0
for i in range(MAX_A_I - 1, 0, -1):
    for j in range(i, MAX_A_I, i):
        cur[j] = i
    if i <= n:
        ans += cur[a[i - 1]]
print(ans)
