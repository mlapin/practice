#include <algorithm>
#include <cassert>
#include <ctime>
#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>

using namespace std;

bool is_new(unordered_multimap<int,int> &pairs, int a, int b) {
    auto p = pairs.equal_range(a);
    for (auto it = p.first; it != p.second; ++it) {
        if (it->second == b) return false;
    }
    pairs.insert({a, b});
    return true;
}

vector<vector<int>> threeSum1(vector<int>& a) {
    int n = a.size();
    unordered_multimap<int,int> map;
    for (int i = 0; i < n; ++i) map.insert({a[i], i});
    unordered_multimap<int,int> pairs;
    vector<vector<int>> res;
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            int sum = -(a[i] + a[j]);
            auto p = map.equal_range(sum);
            for (auto it = p.first; it != p.second; ++it) {
                if (it->second > j) {
                    int mi = min(sum, min(a[i], a[j]));
                    int ma = max(sum, max(a[i], a[j]));
                    if (is_new(pairs, mi, ma))
                        res.emplace_back(initializer_list<int>{mi, -(mi+ma), ma});
                    break;
                }
            }
        }
    }
    return res;
}

vector<vector<int>> threeSum2(vector<int>& nums) {
    int n = nums.size();
    vector<int> a(nums);
    sort(a.begin(), a.end());
    vector<vector<int>> res;
    for (int i = 0, prev = numeric_limits<int>::max(); i < n-2; ++i) {
        if (a[i] == prev) continue;
        prev = a[i];
        int mi = -(a[i]+1)/2, ma = -2*a[i];
        for (int j = n-1; j > i+1 && a[j] >= mi; --j) {
            if (a[j] > ma) continue;
            int s = a[i] + a[j];
            if (binary_search(&a[i+1], &a[j], -s)) {
                res.emplace_back(initializer_list<int>{a[i], -s, a[j]});
                ma = a[j] - 1;
            }
        }
    }
    return res;
}

struct vec_cmp {
    bool operator()(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) {
            if (a[1] == b[1]) {
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
        cout << "too many triplets to show (" << res.size() << ")" << endl;
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
    //vector<int> a({-1,0,1,2,-1,-4,2,1,-2,1,1,-2,-1,3,4,-4,-3,2});
    
    std::vector<int> a({7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6});

    clock_t startcputime;
    double cpu_duration;
    
    startcputime = clock();
    auto res1 = threeSum1(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    startcputime = clock();
    auto res2 = threeSum2(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    show_result(res1);
    show_result(res2);
    
}
