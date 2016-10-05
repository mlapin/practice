#include <ctime>
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

// Note: this version does not check for boundary cases
// that can not happen when called from maximalRectangle().
// See largest_rectangle_in_histogram/main.cpp for a proper implementation.
int largestRectangleArea(vector<int>& a) {
    int n = a.size(), ma = 0;
    stack<int> x;
    for (int i = 0; i < n; ++i) {
        while (!x.empty() && a[i] < a[x.top()]) {
            int h = a[x.top()];
            x.pop();
            int j = x.empty() ? -1 : x.top();
            ma = max(ma, h * (i - j - 1));
        }
        x.push(i);
    }
    return ma;
}

int maximalRectangle(vector<vector<char>>& mat) {
    if (mat.empty()) return 0;
    if (mat[0].empty()) return 0;
    int n = mat[0].size(), ma = 0;
    vector<int> a(n+1);
    for (const auto &row : mat) {
        for (int i = 0; i < n; ++i) {
            a[i] = (row[i] - '0') * (a[i] + 1);
        }
        ma = max(ma, largestRectangleArea(a));
    }
    return ma;
}

int maximalRectangle1(vector<vector<char>>& mat) {
    if (mat.empty()) return 0;
    if (mat.front().empty()) return 0;
    int n = mat.size(), m = mat.front().size(), ma = 0;
    vector<int> a(n*m);
    for (int i = 0; i < n; ++i) {
        int r = m*i, s = 0;
        copy(mat[i].begin(), mat[i].end(), &a[r]);
        for (int j = 0; j < m; ++j) {
            if (a[r+j] == '1') {
                a[r+j] = ++s;
            } else {
                a[r+j] = 0;
                ma = max(ma, s);
                s = 0;
            }
        }
        ma = max(ma, s);
    }
    for (int h = 1; h < n; ++h) {
        for (int i = 0; i < n-h; ++i) {
            int r = m*i, s = m*(i+1);
            for (int j = 0; j < m; ++j) {
                a[r+j] = min(a[r+j], a[s+j]);
                ma = max(ma, (h+1)*a[r+j]);
            }
        }
    }
    return ma;
}

int main() {
    vector<string> t = {
        "10100",
        "10111",
        "11111",
        "10111",
        "11111",
        "10010",
        "10100",
        "10111",
        "11111",
        "10100",
        "10111",
        "11111"
    };

    vector<vector<char>> a;
    for (const auto & s : t) {
        a.emplace_back(s.begin(), s.end());
    }

    clock_t startcputime;
    double cpu_duration;

    startcputime = clock();
    auto r = maximalRectangle(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    startcputime = clock();
    auto r1 = maximalRectangle1(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << "max area: " << r << endl;
    cout << "max area: " << r1 << endl;
}
