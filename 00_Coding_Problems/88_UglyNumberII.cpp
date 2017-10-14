class Solution {
public:
    int nthUglyNumber(int n) {
        int idx2 = 0;
        int idx3 = 0;
        int idx5 = 0;
        vector<int> dp;
        dp.push_back(1);
        while(dp.size() < n) {
            dp.push_back(min(dp[idx2]*2, min(dp[idx3]*3, dp[idx5]*5)));
            if(dp.back() == dp[idx2]*2) idx2++;
            if(dp.back() == dp[idx3]*3) idx3++;
            if(dp.back() == dp[idx5]*5) idx5++;
        }
        return dp.back();
    }
};