#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    assert(1 <= n && n <= 1000000);
    i64 ans = 0;
    const int max = 1000000;
    std::vector<i64> seen(max+1, 0);
    for(int i = 1; i < n+1; i++) {
        i64 a;
        std::cin >> a;
        assert(i <= a && a <= max);
        seen[a]++;
        for(int j = i; j <= max; j += i) {
            ans += seen[j] * i;
            seen[j] = 0;
        }
    }
    for(int i = n+1; i <= max; i++) {
        for(int j = i; j <= max; j+=i) {
            ans += seen[j] * i;
            seen[j] = 0;
        }
    }
    std::cout << ans << '\n';
}