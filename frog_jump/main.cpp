#include <ctime>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool canCross(vector<int> &a, int n, int b, int k, vector<bool> &mem) {
    if (b == n-1) return true;
    if (mem[n*k + b]) return false;
    int i = b+1;
    for (int j = max(k-1, 1); j <= k+1; ++j) {
        int dest = a[b] + j;
        for (; i < n && a[i] <= dest; ++i) {
            if (a[i] == dest) {
                if (canCross(a, n, i, j, mem)) {
                    return true;
                } else {
                    break;
                }
            }
        }
    }
    mem[n*k + b] = true; // visited; cannot cross
    return false;
}

bool canCross(vector<int> &a) {
    if (a.size() < 2) return true;
    int n = a.size(), k = 1;
    vector<bool> mem(n*n);
    for (int i = 1; i < n && a[i] <= k; ++i) {
        if (a[i] == k) return canCross(a, n, i, k, mem);
    }
    return false;
}



bool canCross1(vector<int> &a, int n, int b, int k, vector<int> &mem) {
    if (b == n-1) return true;
    if (mem[n*k + b]) return mem[n*k + b] == 1;
    bool ok = false;
    int i = b+1;
    for (int j = max(k-1, 1); j <= k+1 && !ok; ++j) {
        int dest = a[b] + j;
        for (; i < n && a[i] <= dest; ++i) {
            if (a[i] == dest) {
                ok |= canCross1(a, n, i, j, mem);
                break;
            }
        }
    }
    mem[n*k + b] = ok ? 1 : -1;
    return ok;
}

bool canCross1(vector<int> &a) {
    if (a.size() < 2) return true;
    int n = a.size(), k = 1;
    vector<int> mem(n*n);
    for (int i = 1; i < n && a[i] <= k; ++i) {
        if (a[i] == k) return canCross1(a, n, i, k, mem);
    }
    return false;
}



typedef vector<unordered_map<int, bool>> mem_t;

bool canCross2(vector<int> &a, int n, int b, int k, mem_t &mem) {
    if (b == n-1) return true;
    auto it = mem[b].find(k);
    if (it != mem[b].end()) return false;
    int i = b+1;
    for (int j = max(k-1, 1); j <= k+1; ++j) {
        int dest = a[b] + j;
        for (; i < n && a[i] <= dest; ++i) {
            if (a[i] == dest) {
                if (canCross2(a, n, i, j, mem)) {
                    return true;
                } else {
                    break;
                }
            }
        }
    }
    mem[b][k] = false;
    return false;
}

bool canCross2(vector<int> &a) {
    if (a.size() < 2) return true;
    int n = a.size(), k = 1;
    mem_t mem(n);
    for (int i = 1; i < n && a[i] <= k; ++i) {
        if (a[i] == k) return canCross2(a, n, i, k, mem);
    }
    return false;
}

int main() {
    //vector<int> a = {0,1,3,5,6,8,12,17}; // 1
    //vector<int> a = {0,1,2,3,4,8,9,11}; // 0
    vector<int> a = {0,0,0,1,3,4,5,7,9,10,12}; // 1
    /*vector<int> a;
    a.push_back(0);
    for (int i = 1; i < 1100; ++i)
        a.push_back(i);*/

    clock_t startcputime;
    double cpu_duration;

    startcputime = clock();
    auto r = canCross(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    startcputime = clock();
    auto r1 = canCross1(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    startcputime = clock();
    auto r2 = canCross2(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << r << endl;
    cout << r1 << endl;
    cout << r2 << endl;
}
