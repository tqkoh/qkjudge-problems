#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using i64 = std::int64_t;

const int MIN_N = 1;
const int MAX_N = 100000;
const i64 MIN_M = 1;
const i64 MAX_M = 1000000000000000000;
const int MIN_Q = 1;
const int MAX_Q = 100000;
const i64 MIN_B = 1;
const i64 MAX_B = 1000000000000000000;

int main() {
	int n;
	i64 m;
	std::cin >> n >> m;
	assert(MIN_N <= n && n <= MAX_N);
	assert(MIN_M <= m && m <= MAX_M);
	std::vector<i64> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		assert(1 <= a[i] && a[i] <= m);
	}
	std::set<i64> set;
	set.insert(m + 1);
	std::vector<i64> f;
	for(int i = n - 1; i >= 0; i--) {
		if(set.find(a[i]) == set.end()) {
			set.insert(a[i]);
			f.emplace_back(a[i]);
		}
	}
	std::reverse(f.begin(), f.end());
	std::vector<std::pair<i64, i64>> g;
	i64 now = 1;
	for(auto val : set) {
		if(now == val) {
			now = val + 1;
		} else {
			g.emplace_back(now, val - 1);
			now = val + 1;
		}
	}
	int up = g.size();
	std::vector<i64> cnt(up + 1, 0);
	for(int i = 0; i < up; i++) {
		auto [l, r] = g[i];
		cnt[i + 1] = cnt[i] + r - l + 1;
	}
	int q;
	std::cin >> q;
	assert(MIN_Q <= q && q <= MAX_Q);
	i64 fsz = f.size();
	i64 gsz = m - fsz;
	auto get_g = [&](i64 x) -> i64 {
		int idx = std::lower_bound(cnt.begin(), cnt.end(), x) - cnt.begin();
		idx--;
		x -= cnt[idx];
		assert(x > 0);
		auto [l, r] = g[idx];
		i64 ret = l + x - 1;
		assert(l <= ret && ret <= r);
		return ret;
	};
	while(q--) {
		i64 b;
		std::cin >> b;
		if(b <= n) {
			std::cout << a[b - 1] << '\n';
			continue;
		}
		b -= n;
		if(b <= gsz) {
			std::cout << get_g(b) << '\n';
			continue;
		}
		b -= gsz;
		b = (b - 1) % m + 1;
		if(b <= fsz) {
			std::cout << f[b - 1] << '\n';
		} else {
			b -= fsz;
			assert(1 <= b && b <= gsz);
			std::cout << get_g(b) << '\n';
		}
	}
	return 0;
}
