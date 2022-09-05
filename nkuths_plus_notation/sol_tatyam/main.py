#!/usr/local/bin/pypy3
N, A, B = map(int, input().split())
if N == 1:
    print(A + B)
elif N == 2:
    print(A * B)
else:
    print(A ** B)
