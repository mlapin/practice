#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minDistance(string w1, string w2) {
    if (w1.empty()) return w2.size();
    if (w2.empty()) return w1.size();
    string &a = w1.size() > w2.size() ? w1 : w2;
    string &b = w1.size() > w2.size() ? w2 : w1;
    int n = a.size(), m = b.size(), m1 = m+1;
    vector<int> d(2*m1);
    for (int j = 0; j <= m; ++j) d[j] = j;
    for (int i = 1; i <= n; ++i) {
        int mk = m1 * (i % 2), mp = m1 * ((i-1) % 2);
        d[mk] = i;
        for (int j = 1; j <= m; ++j) {
            int d1 = d[mp + j-1];
            if (a[i-1] != b[j-1]) d1 += 1;
            int d2 = d[mk + j-1] + 1;
            int d3 = d[mp + j] + 1;
            d[mk + j] = min(d1, min(d2, d3));
        }
    }
    return d[m1*(n%2) + m];
}

int main() {
    string a = "ababcd";
    string b = "abcde";

    clock_t startcputime;
    double cpu_duration;

    startcputime = clock();
    int d = minDistance(a, b);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << "min distance: " << d << endl;
}
