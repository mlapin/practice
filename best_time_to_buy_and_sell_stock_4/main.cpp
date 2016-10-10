// any number of transactions
int maxProfit(vector<int>& a) {
    if (a.empty()) return 0;
    int p = 0, b = a[0];
    for (auto x : a) {
        p += max(0, x - b);
        b = x;
    }
    return p;
}

// at most k transactions
int maxProfit(int k, vector<int>& a) {
    if (a.size() < 2 || k < 1) return 0;
    if (k >= a.size()/2) return maxProfit(a);
    vector<int> p(a.size());
    while (k-- > 0) {
        int mp = 0, b = a[0];
        for (int i = 1; i < a.size(); ++i) {
            b = min(b, a[i] - p[i]);
            mp = max(mp, a[i] - b);
            p[i] = mp;
        }
    }
    return p.back();
}
