#include <iostream>
#include <cassert>

int main() {
    int n;
    std::cin >> n;
    int m = n;
    assert(2 <= n && n <= 10000);
    int a = 1;
    n--;
    int b = std::min(n, 5000);
    n -= b;
    a += n;
    assert(a + b == m);
    std::cout << a << " " << b << '\n';
}