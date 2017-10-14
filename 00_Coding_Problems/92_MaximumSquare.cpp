class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0)
            return 0;
        int col = matrix[0].size();
        if(col == 0) 
            return 0;
        vector<int> dp(col);
        int maxSq = 0;
        for(int j = 0; j < col; j++) {
            dp[j] = matrix[0][j] == '0'? 0:1;
            maxSq = max(maxSq, dp[j]);
        }
        int upperleft;
        for(int i = 1; i < row; i++) {
            upperleft = matrix[i-1][0] == '0'? 0:1;
            dp[0] = matrix[i][0] == '0'? 0:1;
            maxSq = max(maxSq, dp[0]);
            for(int j = 1; j < col; j++) {
                int tmp = dp[j];
                if(matrix[i][j] == '1')
                    dp[j] = 1 + min(upperleft, min(dp[j-1], dp[j]));
                else
                    dp[j] = 0;
                upperleft = tmp;
                maxSq = max(maxSq, dp[j]);
            }
        }
        return maxSq*maxSq;
        
    }
};