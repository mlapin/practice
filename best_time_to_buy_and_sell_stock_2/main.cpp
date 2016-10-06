int maxProfit(vector<int>& a) {
    if (a.empty()) return 0;
    int p = 0, b = a[0];
    for (auto x : a) {
        p += max(0, x - b);
        b = x;
    }
    return p;
}
