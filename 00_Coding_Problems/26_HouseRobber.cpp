class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return 0;
        
        int max_wait = 0;
        int max_robbed = 0;
        for (int i = 0; i < n; ++i){
            int tmp = max_wait;
            max_wait = max(tmp, max_robbed);
            max_robbed = nums[i] + tmp;
        }
        return max(max_wait, max_robbed);
    }
};