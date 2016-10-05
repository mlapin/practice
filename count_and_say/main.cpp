#include <ctime>
#include <iostream>
#include <string>

using namespace std;

string countAndSay(string &s) {
    string r;
    char c = s[0], cnt = '0';
    for (auto x : s) {
        if (x == c) {
            ++cnt;
        } else {
            r.push_back(cnt);
            r.push_back(c);
            c = x;
            cnt = '1';
        }
    }
    r.push_back(cnt);
    r.push_back(c);
    return r;
}

string countAndSay(int n) {
    if (n < 1) return "";
    string s{"1"};
    while (n-- > 1)
        s = countAndSay(s);
    return s;
}

int main() {
    int n = 10;

    clock_t startcputime;
    double cpu_duration;

    startcputime = clock();
    auto r = countAndSay(n);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << r << endl;
}
