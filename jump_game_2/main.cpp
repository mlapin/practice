#include <ctime>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int jump(vector<int> &a) {
    if (a.size() < 2) return 0;
    int n = a.size(), num = 0, e = 1;
    for (int b = 0; b < e && e < n; ++num) {
        int k = e;
        for (int i = e-1; i >= b && k < n; --i)
            k = max(k, i + a[i] + 1);
        b = e;
        e = k;
    }
    return e >= n ? num : -1;
}

struct Node {
    int i;
    int h;
    int d;
    Node(int x, int y, int z) : i(x), h(y), d(z) {}
};

bool operator<(const Node &a, const Node &b) {
    return a.d > b.d;
}

int jump1(vector<int>& a) {
    if (a.size() < 2) return 0;
    int n = a.size();
    priority_queue<Node> q;
    vector<bool> v(n);
    q.emplace(0,0,0);
    while(!q.empty()) {
        const auto &p = q.top();
        int i = p.i, h = p.h;
        q.pop();
        if (v[i]) continue;
        v[i] = true;
        for (int j = min(a[i], n-1-i); j > 0; --j) {
            int k = i+j, d = n-1-k-a[k];
            if (k == n-1) return h+1;
            if (!v[k]) {
                q.emplace(k, h+1, d);
                if (d <= 0) break;
            }
        }
    }
    return 0;
}

int main() {
    //vector<int> a = {3,2,1,0,0};
    vector<int> a = {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    /*vector<int> a;
    for (int i = 25000; i > 0; --i)
        a.push_back(i);
    a.push_back(1);
    a.push_back(0);*/

    clock_t startcputime;
    double cpu_duration;

    startcputime = clock();
    auto r = jump(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    startcputime = clock();
    auto r1 = jump1(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << r << endl;
    cout << r1 << endl;
}
