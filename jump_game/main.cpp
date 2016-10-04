#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& a) {
    if (a.size() < 2) return true;
    int n = a.size(), e = 1;
    for (int b = 0; b < e && e < n;) {
        int k = e;
        for (int i = e-1; i >= b && k < n; --i)
            k = max(k, i + a[i] + 1);
        b = e;
        e = k;
    }
    return e >= n;
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
    auto r = canJump(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << r << endl;
}
