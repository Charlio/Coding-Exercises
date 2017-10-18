class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return findTargetSumWays(nums, S, 0);
    }
    
    int findTargetSumWays(vector<int>& nums, int S, int pos) {
        if(pos == nums.size()) {
            if(S == 0)
                return 1;
            else
                return 0;
        } else {
            return findTargetSumWays(nums, S-nums[pos], pos+1) + findTargetSumWays(nums, S+nums[pos], pos+1);
        }        
    }
};