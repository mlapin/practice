int maxProfit(std::vector<int> &a) {
    if (a.size() < 2) return 0;
    int hold = 0, buy = -a[0], sell = 0;
    for (int i = 0; i < a.size(); ++i) {
        int prev = hold;
        hold = max(hold, sell);
        buy = max(buy, prev - a[i]);
        sell = buy + a[i];
    }
    return max(hold, sell);
}
