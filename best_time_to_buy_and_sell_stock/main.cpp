int maxProfit(vector<int>& a) {
    if (a.empty()) return 0;
    int p = 0, b = a[0];
    for (auto x : a) {
        b = x < b ? x : b;
        p = max(p, x - b);
    }
    return p;
}
