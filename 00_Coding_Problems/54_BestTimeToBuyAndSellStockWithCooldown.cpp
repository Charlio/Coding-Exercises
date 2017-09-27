class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int buy = INT_MIN, sell = 0, prev_buy, prev_sell = 0;
        for (int i = 0; i < n; i++){
            prev_buy = buy;
            buy = max(prev_buy, prev_sell - prices[i]);
            prev_sell = sell;
            sell = max(prev_sell, prev_buy + prices[i]);
        }
        return sell;
    }
};