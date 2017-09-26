class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        if (k >= n/2){
            int profit = 0;
            for (int i = 1; i < n; i++){
                profit += max(0, prices[i] - prices[i-1]);
            }
            return profit;
        }
        //vector<vector<int> > dp(k+1, vector<int>(n, 0));
        vector<int> dp(n, 0);
        // dp[j][i] represents max profit with at most j transactions up to prices[i], i excluded
        // dp[j][i] = max(dp[j][i-1], prices[i] + max(dp[j-1][s] - prices[s])), 0<= s < i
        for (int j = 1; j <= k; j++){
            int tmpMax = dp[0] - prices[0];
            for (int i = 1; i < n; i++){
                int tmp = dp[i];
                dp[i] = max(dp[i-1], prices[i] + tmpMax);
                tmpMax = max(tmpMax, tmp - prices[i]);
            }
        }
        return dp[n-1];
    }
};