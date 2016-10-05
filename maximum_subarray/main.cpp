#include <ctime>
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int maxSubArray(vector<int>& a) {
    if (a.empty()) return 0;
    int ms = a[0], i = 1, n = a.size();
    while (ms <= 0 && i < n) {
        ms = max(ms, a[i++]);
    }
    for (int s = ms; i < n; ++i) {
        s = max(0, s + a[i]);
        ms = max(ms, s);
    }
    return ms;
}

int main() {
    vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};

    clock_t startcputime;
    double cpu_duration;

    startcputime = clock();
    auto r = maxSubArray(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << "max area: " << r << endl;
}
