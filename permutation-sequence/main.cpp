string getPermutation(int n, int k) {
    if (n < 1 || k < 1) return {};
    string a(n, '0');
    vector<int> q(n);
    for (int i = 1, r = k-1; i <= n; ++i) {
        a[n-i] += i;
        q[n-i] = r % i;
        r = r / i;
    }
    for (int i = 0; i < n-1; ++i) {
        int j = n-1 - q[i];
        while (i < j--) swap(a[j], a[j+1]);
    }
    return a;
}

/*
n = 4
k = 17
17: 3 4 1 2 

16/1 = 16, 0
16/2 = 8, 0
8/3  = 2, 2
2/4  = 0, 2

idx: 0 1 2 3
idx: 3 2 1 0
val: 4 3 2 1
*/
