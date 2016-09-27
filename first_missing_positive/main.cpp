#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int>& a) {
    int n = a.size(); 
    for (int i = 0; i < n; ++i) {
        while (0 < a[i] && a[i] <= n && a[i] != a[a[i]-1])
            swap(a[i], a[a[i]-1]);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != i + 1) return i+1;
    }
    return n+1;
}


int main() {
    vector<int> a({10,1,2,3,4,5,6,7,8,9}), b;

    clock_t startcputime;
    double cpu_duration;

    for (auto i : a) cout << i << " ";
    cout << endl;

    startcputime = clock();
    b = a;
    int r = firstMissingPositive(b);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << r << endl;
}
