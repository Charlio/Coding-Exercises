class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n == 0 || s[0] == '0')
            return 0;
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 1; i < n; i++) {
            if(s[i-1] == '1' || s[i-1] == '2') {
                if(s[i] == '0') {
                    dp[i+1] = dp[i-1];
                } else if(s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6') {
                    dp[i+1] = dp[i] + dp[i-1];
                } else {
                    dp[i+1] = dp[i];
                }
            } else { 
                if(s[i] != '0') {
                    dp[i+1] = dp[i];
                } else {
                    return 0;
                }
            }
        }
        return dp[n];
    }
};