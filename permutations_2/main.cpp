#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void permute(vector<int> &a, vector<bool> &sel,
        vector<int> &q, vector<vector<int>> &r) {
    if (q.size() == a.size()) {
        r.push_back(q);
    } else {
        int prev = numeric_limits<int>::max();
        for (int i = 0; i < a.size(); ++i) {
            if (sel[i] || a[i] == prev) continue;
            prev = a[i];
            sel[i] = true;
            q.push_back(a[i]);
            permute(a, sel, q, r);
            q.pop_back();
            sel[i] = false;
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> r;
    vector<bool> sel(nums.size());
    vector<int> a(nums), q;
    sort(a.begin(), a.end());
    q.reserve(a.size());
    permute(a, sel, q, r);
    return r;
}

int main() {
    vector<int> a({1,1,3,2});

    clock_t startcputime;
    double cpu_duration;

    for (auto i : a) cout << i << " ";
    cout << endl;
    
    startcputime = clock();
    auto r = permuteUnique(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    for (auto v : r) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
}
