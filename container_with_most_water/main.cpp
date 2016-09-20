#include <algorithm>
#include <cassert>
#include <ctime>
#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>

using namespace std;

int maxArea(vector<int>& a) {
    if (a.size() < 2) return 0;
    int s = 0, b = 0, e = 0;
    auto i = a.begin(), j = a.end()-1;
    while (i != j) {
        b = *i;
        e = *j;
        int t = min(b, e) * distance(i, j);
        if (s < t) s = t;
        if (b < e) {
            while (i != j && *i <= b) ++i;
        } else {
            while (i != j && *j <= e) --j;
        }
            
    }
    return s;
}

int main() {
    vector<int> a({56,57,-47,-14,23,31,20,39,-51,7,-4,43,-53,32,24,56,28});

    clock_t startcputime;
    double cpu_duration;

    startcputime = clock();
    auto area = maxArea(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << "area: " << area << endl;
}

