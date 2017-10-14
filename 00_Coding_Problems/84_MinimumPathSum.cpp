class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> dp(col, INT_MAX);
        dp[col-1] = 0;
        for(int i = row-1; i >= 0; i--) {
            dp[col-1] = grid[i][col-1] + dp[col-1];
            for(int j = col-2; j >= 0; j--) {
                dp[j] = grid[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};