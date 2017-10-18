class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> prev(3, 0);
        for(int i = 0; i < costs.size(); i++) {
            int red = costs[i][0] + min(prev[1], prev[2]);
            int blue = costs[i][1] + min(prev[0], prev[2]);
            int green = costs[i][2] + min(prev[0], prev[1]);
            prev[0] = red;
            prev[1] = blue;
            prev[2] = green;
        }
        return min(min(prev[0], prev[1]), prev[2]);
    }
};