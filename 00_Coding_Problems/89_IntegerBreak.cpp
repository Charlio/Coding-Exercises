class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= (i+1)/2; j++) {
                dp[i] = max(dp[j-1]*(i+1-j), max(j*dp[i-j], max(j*(i+1-j), max(dp[i], dp[j-1]*dp[i-j]))));
            }
        }
        return dp[n-1];
    }
};