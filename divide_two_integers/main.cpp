#include <ctime>
#include <iostream>
#include <limits>

using namespace std;

int divide(int dividend, int divisor) {
    if (divisor == 0) return numeric_limits<int>::max();
    if (divisor == 1) return dividend;
    int sign = -1;
    if (dividend > 0) {
        sign = -sign;
        dividend = -dividend;
    }
    if (divisor > 0) {
        sign = -sign;
        divisor = -divisor;
    }
    int res = 0;
    while (dividend <= divisor) {
        int a = divisor, k = -1;
        while (dividend - a <= a) {
            a += a;
            k += k;
        }
        res += k;
        dividend -= a;
    }
    if (sign < 0) {
        if (res == numeric_limits<int>::min())
            return numeric_limits<int>::max();
        return -res;
    }
    return res;
}

int main() {
    int a = numeric_limits<int>::min();
    int b = -1;

    clock_t startcputime;
    double cpu_duration;
    
    startcputime = clock();
    auto r = divide(a, b);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << a << " / " << b << " = " << r << " (computed)" << endl;
    cout << a << " / " << b << " = " << a/b << " (expected)" << endl;
}
