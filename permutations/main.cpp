#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void permute(vector<int> &a, int b, vector<vector<int>> &r) {
    if (b >= a.size()) {
        r.push_back(a);
    } else {
        for (int i = b; i < a.size(); ++i) {
            swap(a[b], a[i]);
            permute(a, b+1, r);
            swap(a[b], a[i]);
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> r;
    vector<int> a(nums);
    permute(a, 0, r);
    return r;
}

int main() {
    vector<int> a({1,3,2});

    clock_t startcputime;
    double cpu_duration;

    for (auto i : a) cout << i << " ";
    cout << endl;
    
    startcputime = clock();
    auto r = permute(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    for (auto v : r) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
}
