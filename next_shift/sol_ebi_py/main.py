import sys
import bisect

input = sys.stdin.readline

n,m = map(int, input().split())
a = list(map(int, input().split()))

s = set()
f = []
s.add(m+1)

for x in reversed(a):
    if x in s:
        continue
    else:
        f.append(x)
        s.add(x)
f.reverse()

s = list(s)
s.sort()

g = []
cnt = [0]
now = 1

for x in s:
    if now < x:
        g.append((now, x-1))
        cnt.append(cnt[-1] + x-now)
    now = x + 1
gsz = cnt[-1]

q = int(input())
b = list(map(int, input().split()))

def get_g(x: int) -> int:
    idx = bisect.bisect_left(cnt, x) - 1
    x -= cnt[idx]
    (l, r) = g[idx]
    return l + x -1

for x in b:
    if x <= n:
        print(a[x-1])
        continue
    x -= n
    x = (x-1)%m + 1

    if x <= gsz:
        print(get_g(x))
    else:
        print(f[x-gsz-1])