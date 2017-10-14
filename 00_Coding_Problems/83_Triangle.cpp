class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row= triangle.size();
        vector<int> cur_sums(row+1, 0);
        for(int i = row-1; i >= 0; i--) {
            for(int j = 0; j < row; j++) {
                cur_sums[j] = triangle[i][j] + min(cur_sums[j], cur_sums[j+1]);
            }
        }
        return cur_sums[0];
    }
};