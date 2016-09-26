#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& a, int t) {
    if (a.empty() || t < a.front() || a.back() < t)
        return {-1, -1};
    int n = a.size(), b = 0, e = n-1, ee = e, i = -1, j = -1;
    while (b <= e) {
        int k = (b+e)/2;
        if (t < a[k]) {
            ee = e = k-1;
        } else if (a[k] < t) {
            b = k+1;
        } else if (k > 0 && a[k-1] == t) {
            e = k-1;
        } else {
            i = k;
            break;
        }
    }
    if (i < 0) return {-1, -1};
    b = j = i;
    e = ee;
    while (b < e) {
        int k = (b+e)/2;
        if (a[k] > t) {
            e = k-1;
        } else if (k < n-1 && a[k+1] == t) {
            b = j = k+1;
        } else {
            j = k;
            break;
        }
    }
    return {i, j};
}


int main() {
    vector<int> a({1,2,2,3,3,3,4,5});
    int t = 3;

    clock_t startcputime;
    double cpu_duration;

    for (auto i : a) cout << i << " ";
    cout << endl;
    
    startcputime = clock();
    auto r = searchRange(a, t);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;
    
    for (int i = r[0]; 0 < i && i <= r[1]; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}
