#include <algorithm>
#include <cassert>
#include <ctime>
#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> fourSum(const vector<int>& a, int t) {
    vector<int> b(a);
    sort(b.begin(), b.end());
    int n = b.size();
    vector<vector<int>> res;
    for (int p = 0, bp = numeric_limits<int>::max(); p < n-3; ++p) {
        if (b[p] == bp) continue;
        bp = b[p];
        for (int r = n-1, br = numeric_limits<int>::min(); r > p+2; --r) {
            if (b[r] == br) continue;
            br = b[r];
            int i = p+1, j = r-1, spr = bp + br;
            while (i < j) {
                int s = spr + b[i] + b[j];
                if (s < t) {
                    ++i;
                } else if (s > t) {
                    --j;
                } else {
                    res.emplace_back(initializer_list<int>{b[p], b[i], b[j], b[r]});
                    int bi = b[i], bj = b[j];
                    while (i < j && b[i] == bi) ++i;
                    while (i < j && b[j] == bj) --j;
                }
            }
        }
    }
    return res;
}

struct vec_cmp {
    bool operator()(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) {
            if (a[1] == b[1]) {
                if (a[2] == b[2]) {
                    return a[3] < b[3];
                }
                return a[2] < b[2];
            }
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
};

void show_result(vector<vector<int>> &res) {
    sort(res.begin(), res.end(), vec_cmp());

    int max_show = 20;
    if (res.size() > max_show) {
        cout << "too many tuples to show (" << res.size() << ")" << endl;
        cout << "showing the first " << max_show << "..." << endl;
        res.resize(max_show);
    }

    cout << "Result:" << endl;
    for (auto v : res) {
        for (auto i : v) {
            cout << "\t" << i;
        }
        cout << endl;
    }
}

int main() {
    std::vector<int> a({7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6});
    int target = 50;

    clock_t startcputime;
    double cpu_duration;

    startcputime = clock();
    auto res = fourSum(a, target);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    show_result(res);
}
