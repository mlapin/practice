#include <iostream>

// n choose k
int binomial(int n, int k) {
    if (k > n/2) return binomial(n, n-k);
    int b = 1;
    for (int i = 1; i <= k; ++i) {
        b *= n - i + 1;
        b /= i;
    }
    return b;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << binomial(i, j) << "\t";
        }
        std::cout << std::endl;
    }
}
