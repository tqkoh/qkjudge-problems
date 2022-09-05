#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

namespace ebi {

using i64 = std::int64_t;

template <std::uint_fast64_t Modulus>
class modint {
    using u64 = std::uint_fast64_t;

   public:
    u64 a;

    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr u64 &val() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }
    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }
    constexpr modint &operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint &operator/=(modint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    constexpr modint operator-() const { return modint() - *this; }
    bool operator==(const u64 rhs) { return a == rhs; }
    bool operator!=(const u64 rhs) { return a != rhs; }
    constexpr modint &operator++() {
        a++;
        if (a == mod()) a = 0;
        return *this;
    }
    constexpr modint &operator--() {
        if (a == 0) a = mod();
        a--;
        return *this;
    }

    modint pow(u64 n) const noexcept {
        modint res = 1;
        modint x = a;
        while (n > 0) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
    modint inv() const { return pow(Modulus - 2); }

    static u64 mod() { return Modulus; }
};

using modint998244353 = modint<998244353>;
using modint1000000007 = modint<1000000007>;

template <std::uint_fast64_t Modulus>
std::ostream &operator<<(std::ostream &os, modint<Modulus> a) {
    return os << a.val();
}

using mint = modint998244353;

void main_() {
    int n, k;
    std::cin >> n >> k;
    assert(1 <= n && n <= 200000);
    assert(1 <= k && k <= n);
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        assert(1 <= a[i] && a[i] <= 1000000000);
    }
    mint ans = 0;
    std::vector<mint> fact(n + 1, 1), inv_fact(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }
    inv_fact[n] = fact[n].inv();
    for (int i = n; i > 0; i--) {
        inv_fact[i - 1] = inv_fact[i] * i;
    }
    std::sort(a.begin(), a.end());
    auto comb = [&](int p, int q) -> mint {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fact[p] * inv_fact[q] * inv_fact[p - q];
    };
    for(int i = k-1; i < n; i++) {
        ans += comb(i, k-1) * a[i];
    }
    std::cout << ans << '\n';
}

}  // namespace ebi

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ebi::main_();
}