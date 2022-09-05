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
    for (int i = 1; i < n+1; i++) {
        int a;
        std::cin >> a;
        assert(i <= a && a <= 1000000);
        int flag = 0;
        int r = 1e9;
        for (int j = 1; j * j <= a; j++) {
            if (a % j == 0) {
                if (j >= i) {
                    ans += j;
                    flag = 1;
                    break;
                }
                if(a/j >= i) r = std::min(r, a/j);
            }
        }
        if(flag == 0) {
            ans += r;
        }
    }
    std::cout << ans << '\n';
}