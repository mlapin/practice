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

vector<int> getPermutation(int n, int k) {
    if (n < 1 || k < 1) return {};
    vector<int> a(n), q(n);
    for (int i = 1, r = k-1; i <= n; ++i) {
        a[n-i] = i;
        q[n-i] = r % i;
        r = r / i;
    }
    for (int i = 0; i < n-1; ++i) {
        int j = n-1 - q[i];
        while (i < j--) swap(a[j], a[j+1]);
    }
    return a;
}

int main() {
    vector<int> a({1,2,3,4,5}); // [2,1,3]

    clock_t startcputime;
    double cpu_duration;

    //for (auto i : a) cout << i << " ";
    //cout << endl;

    startcputime = clock();
    for (int iter = 0; iter < 24; ++iter) {
        cout << iter + 1 << ": ";
        for (auto i : a) cout << i << " ";
        cout << endl;
        nextPermutation(a);
    }
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    auto v = getPermutation(a.size(), 24);
    cout << 24 << ": ";
    for (auto x : v) cout << x << " ";
    cout << endl;
}
