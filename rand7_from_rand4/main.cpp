#include <iostream>
#include <limits>
#include <random>

using namespace std;

class Random {
    mt19937 gen{1};
    uniform_int_distribution<int> r4{0,4};

public:
    int rand4() {
        // generates integers in [0,4]
        return r4(gen);
    }

    int rand7a() {
        // generates integers in [0,7] ("correct")
        int a = 5*rand4() + rand4();
        while (a >= 24) a = 5*rand4() + rand4();
        return a % 8;
    }

    int rand7b() {
        // generates integers in [0,7] (biased)
        int a = 5*rand4(), b = rand4();
        while (a + b >= 24) b = rand4();
        return (a + b) % 8;
    }

    int rand7c() {
        // generates integers in [0,7] (biased)
        int a = rand4(), b = 5*rand4();
        while (a + b >= 24) b = 5*rand4();
        return (a + b) % 8;
    }
};


int main() {
    int a[8], b[8], c[8], n = 1 << 24;
    for (int i = 0; i < 8; ++i) {
        a[i] = b[i] = c[i] = 0;
    }
    Random rng;
    for (int i = 0; i < n; ++i) {
        a[rng.rand7a()]++;
        b[rng.rand7b()]++;
        c[rng.rand7c()]++;
    }
    cout << scientific;
    cout << "1/n = " << 1.0 / n << endl;
    cout << "(a):" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << i << ": " << (a[i] * 1.0 / n - 1.0/8.0) << endl;
    }
    cout << "(b):" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << i << ": " << (b[i] * 1.0 / n - 1.0/8.0) << endl;
    }
    cout << "(c):" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << i << ": " << (c[i] * 1.0 / n - 1.0/8.0) << endl;
    }
}
