#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void helper(int t, int t1, int ai, int bi, int &a1, int &a2, int &b1, int &b2) {
    if (t < t1) {
        if (ai < a2) {
            a1 = ai + 1;
        } else {
            a1 = a2;
            b1 = min(bi + 1, b2);
        }
    } else if (t > t1) {
        if (bi > b1) {
            b2 = bi - 1;
        } else {
            b2 = b1;
            a2 = ai;
        }
    } else {
        b2 = bi;
        if (ai < a2) {
            a1 = ai + 1;
        } else {
            a1 = a2;
            b1 = bi;
        }
    }
}

int nextorinf(vector<int>& a, int i) {
    if (i+1 < a.size()) return a[i+1];
    return numeric_limits<int>::max();
}

double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    if (n == 0 && m == 0) return 0;
    if (m == 0) return (a[(n-1)/2] + a[n/2])/2.0;
    if (n == 0) return (b[(m-1)/2] + b[m/2])/2.0;

    int a1 = 0, a2 = n-1, b1 = 0, b2 = m-1, t1 = (n+m-1)/2;
    int ai = (n-1)/2, bi = (m-1)/2, t = ai + bi + 1;

    while (a1 < a2 || b1 < b2) {
        if (a[ai] <= b[bi]) {
            helper(t, t1, ai, bi, a1, a2, b1, b2);
        } else {
            helper(t, t1, bi, ai, b1, b2, a1, a2);
        }
        ai = (a1 + a2)/2;
        bi = (b1 + b2)/2;
        t  = ai + bi + 1;
    }

    int x1 = max(a[ai], b[bi]);
    if (t > t1) { // t == t1 + 1
        x1 = min(a[ai], b[bi]);
    }
    if (t1 == (n+m)/2)
        return x1;

    int x2 = min(nextorinf(a, ai), nextorinf(b, bi));
    if (t > t1) {
        x2 = min(x2, max(a[ai], b[bi]));
    }
    return (x1 + x2)/2.0;
}

int main() {
    vector<int> a({1,3,4,4,6});
    vector<int> b({2,2,4});

    double m1 = findMedianSortedArrays(a, b);

    vector<int> c(a);
    c.insert(c.end(), b.begin(), b.end());
    sort(c.begin(), c.end());
    
    int i = (c.size() - 1)/2, j = c.size()/2;
    double m2 = (c[i] + c[j])/2.0;
  
    cout << "m1 = " << m1 << endl;
    cout << "m2 = " << m2 << endl;
}
