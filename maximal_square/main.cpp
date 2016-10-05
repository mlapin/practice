#include <ctime>
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int maximalSquare(vector<vector<char>>& mat) {
    if (mat.empty()) return 0;
    if (mat[0].empty()) return 0;
    int n = mat.size(), m = mat[0].size(), ma = 0;
    vector<int> a(m+1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1, d = 0; j <= m; ++j) {
            if (mat[i-1][j-1] == '1') {
                int t = min(d, min(a[j-1], a[j])) + 1;
                d = a[j];
                a[j] = t;
                ma = max(ma, t);
            } else {
                a[j] = 0;
            }
        }
    }
    return ma*ma;
}


int largestSquareArea(vector<int>& a) {
    int n = a.size(), ma = 0;
    stack<int> x;
    for (int i = 0; i < n; ++i) {
        while (!x.empty() && a[i] < a[x.top()]) {
            int h = a[x.top()];
            x.pop();
            int j = x.empty() ? -1 : x.top();
            int w = min(h, i - j - 1);
            ma = max(ma, w*w);
        }
        x.push(i);
    }
    return ma;
}

int maximalSquare1(vector<vector<char>>& mat) {
    if (mat.empty()) return 0;
    if (mat[0].empty()) return 0;
    int n = mat[0].size(), ma = 0;
    vector<int> a(n+1);
    for (const auto &row : mat) {
        for (int i = 0; i < n; ++i) {
            a[i] = (row[i] - '0') * (a[i] + 1);
        }
        ma = max(ma, largestSquareArea(a));
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
    auto r = maximalSquare(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;
    
    startcputime = clock();
    auto r1 = maximalSquare1(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << "max area: " << r << endl;
    cout << "max area: " << r1 << endl;
}
