int maxProfit(vector<int>& a) {
    if (a.empty()) return 0;
    vector<int> v(a.size());
    int mp = 0, n = a.size();
    for (int i = 0, b = a[0], p = 0; i < n; ++i) {
        b = b < a[i] ? b : a[i];
        p = max(p, a[i] - b);
        v[i] += p;
    }
    for (int i = n-1, s = a[n-1], p = 0; i >= 0; --i) {
        s = s > a[i] ? s : a[i];
        p = max(p, s - a[i]);
        mp = max(mp, v[i] + p);
    }
    return mp;
}
