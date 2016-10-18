#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int>& a) {
    if (a.empty()) return;
    auto i = prev(a.end()), j = i;
    while (i != a.begin() && *(--i) >= *j) --j;
    if (*i < *j) {
        j = prev(a.end());
        while (*i >= *j) --j;
        iter_swap(i, j);
        ++i;
    }
    reverse(i, a.end());
}

void nextPermutation1(vector<int>& a) {
    if (a.size() < 2) return;
    int n = a.size(), i = n-2;
    for (; i >= 0; --i) {
        if (a[i] < a[i+1]) {
            int mi = i+1;
            for (int j = i+2; j < n; ++j)
                if (a[j] < a[mi] && a[i] < a[j]) mi = j;
            swap(a[i], a[mi]);
            break;
        }
    }
    sort(&a[i+1], &a[n]);
}

int main() {
    vector<int> a({1,3,2,4}); // [2,1,3]

    clock_t startcputime;
    double cpu_duration;

    for (auto i : a) cout << i << " ";
    cout << endl;
    
    startcputime = clock();
    for (int iter = 0; iter < 20; ++iter) {
        nextPermutation(a);
        for (auto i : a) cout << i << " ";
        cout << endl;
    }
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;
}
