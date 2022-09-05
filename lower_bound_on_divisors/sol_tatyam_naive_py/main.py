#!/usr/bin/env pypy
import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
ans = 0


def f(x):
  for j in range(i + 1, 1001):
    if x % j == 0:
      return j
  for j in range(x // max(1000, i + 1), 0, -1):
    if x % j == 0:
      return x // j


for i in range(N):
  ans += f(A[i])
print(ans)
