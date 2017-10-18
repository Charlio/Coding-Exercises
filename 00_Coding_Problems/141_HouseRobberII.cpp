class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        return max(helper(nums, 0, n-1), helper(nums, 1, n));
    }
    
    int helper(vector<int>& nums, int low, int high) {
        int prev_prev = 0;
        int prev = 0;
        for(int i = low; i < high; i++) {
            int tmp = prev;
            prev = max(prev, prev_prev + nums[i]);
            prev_prev = tmp;
        }
        return prev;
    }
    
};