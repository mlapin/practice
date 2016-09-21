#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int bsearch(vector<int>& a, int b, int e, int t) {
    if (a[b] == t) return b;
    if (a[e] == t) return e;
    while (b < e) {
        int i = (b + e)/2;
        if (a[i] < t)
            b = min(i+1, e);
        else if (a[i] > t)
            e = max(i-1, b);
        else
            return i;
    }
    return a[b] == t ? b : -1;
}

int psearch(vector<int>& a, int b, int e) {
    if (a[b] <= a[e]) return -1;
    while (b < e) {
        int i = (b + e)/2;
        if (b < i && a[b] <= a[i]) b = i;
        if (i < e && a[i] <= a[e]) e = i;
        if (b == e - 1) b = e;
    }
    return b;
}

int search(vector<int>& a, int t) {
    if (a.empty()) return -1;
    int b = 0, e = a.size() - 1;
    int p = psearch(a, b, e);
    if (0 < p && p < e) {
        if (a[b] <= t && t <= a[p-1])
            e = p-1;
        else if (a[p] <= t && t <= a[e])
            b = p;
        else
            return -1;
    }
    return bsearch(a, b, e, t);
}


int main() {
    std::vector<int> a({6,7,8,1,2,3,4,5});
    int t = 4;

    clock_t startcputime;
    double cpu_duration;

    startcputime = clock();
    auto i = search(a, t);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << "i = " << i << endl;
}
