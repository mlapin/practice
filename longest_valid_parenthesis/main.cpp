#include <stack>
#include <string>
#include <ctime>
#include <iostream>

using namespace std;

int longestValidParentheses1(string s) {
    stack<int> q;
    q.push(-1);
    int m = 0;
    for (char c : s) {
        switch(c) {
            case '(':
                q.push(0);
                break;
            case ')':
                int n = 1;
                while (q.top() > 0) { n += q.top(); q.pop(); }
                if (q.top() == 0) {
                    q.pop();
                    while (q.top() > 0) { n += q.top(); q.pop(); }
                    q.push(n);
                    m = max(n, m);
                }
        }
    }
    return 2*m;
}

int longestValidParentheses2(string s) {
    if (s.size() < 2) return 0;
    int n = s.size(), a[s.size()];
    a[n-1] = 0;
    bool any = false;
    for (int i = 0; i < n-1; ++i) {
        any |= a[i] = 2*(s[i] == '(' && s[i+1] == ')');
    }
    if (!any) return 0;
    int m = s.size()/2 + 1, maxlen = 2;
    for (int j = 1; j < m && any; ++j) {
        any = false;
        int r = 2*j + 1;
        for (int i = 0; i < n-r; ++i) {
            int &ai = a[i];
            if (ai > 0) {
                if (i + ai < n && a[i + ai] > 0) {
                    any |= ai += a[i + ai];
                    maxlen = ai > maxlen ? ai : maxlen;
                }
                i += ai - 1;
            } else if (a[i+1] > 0 && i + a[i+1] + 1 < n
                && s[i] == '(' && s[i + a[i+1] + 1] == ')') {
                any |= ai = a[i+1] + 2;
                maxlen = ai > maxlen ? ai : maxlen;
                i += ai - 1;
            }
        }
    }
    return maxlen;
}

int main() {
    string s = "))((())()())()()()))((()))()(";

    clock_t startcputime;
    double cpu_duration;

    startcputime = clock();
    auto r1 = longestValidParentheses1(s);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    startcputime = clock();
    auto r2 = longestValidParentheses2(s);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << "maxlen1: " << r1 << endl;
    cout << "maxlen2: " << r2 << endl;
}
