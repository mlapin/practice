#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& a) {
    if (a.size() < 3) return 0;
    vector<int> b(a.size(), 0);
    int n = a.size(), h = a.front(), s = 0;
    for (int i = 1; i < n-1; ++i) {
        h = max(h, a[i]);
        b[i] = h - a[i];
    }
    h = a.back();
    for (int i = n-2; i > 0; --i) {
        h = max(h, a[i]);
        s += min(b[i], h - a[i]);
    }
    return s;
}

int main() {
    vector<int> a({10, 1, 2, 7, 6, 1, 5});

    clock_t startcputime;
    double cpu_duration;

    for (auto i : a) cout << i << " ";
    cout << endl;

    startcputime = clock();
    auto r = trap(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << "amount trapped: " << r << endl;
}
