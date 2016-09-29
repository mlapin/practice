#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int kMaxHeight = 20000;

int height(vector<vector<int>>& a, vector<vector<int>>& b, int i, int j) {
    return a[i][j] + b[i][j];
}

int trapRainWater(vector<vector<int>>& a) {
    if (a.size() < 3) return 0;
    int n = a.size(), m = a[0].size(), s = 0;
    if (m < 3) return 0;

    vector<vector<int>> b;
    b.emplace_back(m, 0);
    for (int i = 1; i < n-1; ++i) {
        b.emplace_back(m, numeric_limits<int>::max() - kMaxHeight);
        b.back().front() = 0;
        b.back().back() = 0;
    }
    b.emplace_back(m, 0);

    vector<pair<int,int>> q;
    for (int i = 1; i < n-1; ++i) {
        for (int j = 1; j < m-1; ++j) {
            b[i][j] = max(0, min(
                min(height(a, b, i-1, j), height(a, b, i+1, j)),
                min(height(a, b, i, j-1), height(a, b, i, j+1)))
                - a[i][j]);
            int h = height(a, b, i, j);
            if (b[i-1][j] > 0 && height(a, b, i-1, j) > h)
                q.emplace_back(i-1, j);
            if (b[i][j-1] > 0 && height(a, b, i, j-1) > h)
                q.emplace_back(i, j-1);
        }
    }

    while (!q.empty()) {
        int i = q.back().first, j = q.back().second, t = b[i][j];
        q.pop_back();
        b[i][j] = max(0, min(
                min(height(a, b, i-1, j), height(a, b, i+1, j)),
                min(height(a, b, i, j-1), height(a, b, i, j+1)))
                - a[i][j]);
        if (t == b[i][j]) continue;
        int h = height(a, b, i, j);
        if (b[i-1][j] > 0 && height(a, b, i-1, j) > h)
            q.emplace_back(i-1, j);
        if (b[i][j-1] > 0 && height(a, b, i, j-1) > h)
            q.emplace_back(i, j-1);
        if (b[i+1][j] > 0 && height(a, b, i+1, j) > h)
            q.emplace_back(i+1, j);
        if (b[i][j+1] > 0 && height(a, b, i, j+1) > h)
            q.emplace_back(i, j+1);
    }

    for (int i = 1; i < n-1; ++i) {
        auto &v = b[i];
        for (int j = 1; j < m-1; ++j) s += v[j];
    }

    return s;
}



struct Node {
  int i;
  int j;
  int h;
  Node(int x, int y, int z) : i(x), j(y), h(z) {}
};

bool operator<(const Node &a, const Node &b) {
  return a.h > b.h;
}

int trapRainWater2(vector<vector<int>>& a) {
    if (a.size() < 3) return 0;
    int n = a.size(), m = a[0].size(), s = 0;
    if (m < 3) return 0;

    vector<vector<int>> b;
    b.emplace_back(m, 0);
    for (int i = 1; i < n-1; ++i) {
        b.emplace_back(m, numeric_limits<int>::max() - kMaxHeight);
        b.back().front() = 0;
        b.back().back() = 0;
    }
    b.emplace_back(m, 0);

    priority_queue<Node> q;
    for (int i = 1; i < n-1; ++i) {
        for (int j = 1; j < m-1; ++j) {
            b[i][j] = max(0, min(
                min(a[i-1][j] + b[i-1][j], a[i+1][j] + b[i+1][j]),
                min(a[i][j-1] + b[i][j-1], a[i][j+1] + b[i][j+1]))
                - a[i][j]);
            if (b[i][j] > 0)
                q.emplace(i, j, a[i][j] + b[i][j]);
        }
    }

    while (!q.empty()) {
        int i = q.top().i, j = q.top().j, t = b[i][j];
        q.pop();
        b[i][j] = max(0, min(
                min(a[i-1][j] + b[i-1][j], a[i+1][j] + b[i+1][j]),
                min(a[i][j-1] + b[i][j-1], a[i][j+1] + b[i][j+1]))
                - a[i][j]);
        if (t == b[i][j]) continue;
        if (b[i-1][j] > 0) q.emplace(i-1, j, a[i-1][j] + b[i-1][j]);
        if (b[i+1][j] > 0) q.emplace(i+1, j, a[i+1][j] + b[i+1][j]);
        if (b[i][j-1] > 0) q.emplace(i, j-1, a[i][j-1] + b[i][j-1]);
        if (b[i][j+1] > 0) q.emplace(i, j+1, a[i][j+1] + b[i][j+1]);
    }

    for (int i = 1; i < n-1; ++i) {
        auto &v = b[i];
        for (int j = 1; j < m-1; ++j) s += v[j];
    }

    return s;
}


int main() {
    vector<vector<int>> a = {
        {2,3,5,7,4,2,8},
        {4,5,2,0,4,3,5},
        {0,1,4,5,2,7,8},
        {6,4,5,7,6,7,8}
    };

    clock_t startcputime;
    double cpu_duration;

    startcputime = clock();
    auto r = trapRainWater(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << "amount trapped: " << r << endl;
}
