#include <iostream>
#include <vector>

using namespace std;

void walk(const size_t m, const int n, size_t &s) {
    if (n > 0) {
        walk(m, n-1, s);
        s ^= 1 << n-1;
        walk(m, n-1, s);
    } else {
        for (size_t i = m; i > 0; --i)
            cout << bool(s & (1 << i-1));
        cout << endl;
    }
}

void walk_binary_cube(size_t n) {
    if (n > 32) return;
    size_t s = 0;
    walk(n, n, s);
}

int main() {
    for (size_t n = 0; n < 6; ++n) {
        cout << "n = " << n << endl;
        walk_binary_cube(n);
        cout << endl;
    }
}
