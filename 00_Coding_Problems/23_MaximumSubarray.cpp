class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_so_far = INT_MIN;
        int max_end = 0;
        for(int i = 0; i < n; ++i){
            max_end = max(max_end + nums[i], nums[i]);
            max_so_far = max(max_so_far, max_end);
        }
        return max_so_far;
    }
};