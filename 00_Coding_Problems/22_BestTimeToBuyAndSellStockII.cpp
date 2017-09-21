class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int sum = 0;
        int min = prices[0];
        for(int i = 1; i < n; ++i){
            if(prices[i] <= prices[i-1]){
                sum += prices[i-1] - min;
                min = prices[i];
            }
            if(i == n-1){
                sum += prices[i] - min;
            }
        }
        return sum;
    }
};