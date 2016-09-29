#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef set<int>::const_iterator citer_t;

bool combine(citer_t sb, citer_t se, const int t,
        vector<int> &q, vector<vector<int>> &r) {
    if (t < 0) return true;
    q.push_back(*sb);
    if (t == 0) {
        r.push_back(q);
    } else {
        for (auto it = sb; it != se; ++it) {
            if (combine(it, se, t - *it, q, r)) break;
        }
    }
    q.pop_back();
    return t == 0;
}

vector<vector<int>> combinationSum(vector<int>& nums, int t) {
    vector<vector<int>> r;
    vector<int> q;
    set<int> a(nums.begin(), nums.end());
    for (auto it = a.begin(); it != a.end(); ++it) {
        if (combine(it, a.end(), t - *it, q, r)) break;
    }
    return r;
}

int main() {
    vector<int> a({2,3,2,5,1,2,3,4,5,6});
    int t = 7;

    clock_t startcputime;
    double cpu_duration;

    for (auto i : a) cout << i << " ";
    cout << endl;
    
    cout << "t = " << t << endl;

    startcputime = clock();
    auto r = combinationSum(a, t);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << "num combinations: " << r.size() << endl;
    for (auto s : r) {
        for (auto i : s)
            cout << i << " ";
        cout << endl;
    }
}
