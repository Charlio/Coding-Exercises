class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int min_so_far = INT_MAX;
        for(int i = 0; i < n; ++i){
            max_profit = max(max_profit, prices[i] - min_so_far);
            min_so_far = min(min_so_far, prices[i]);
        }
        return max_profit;
    }
};