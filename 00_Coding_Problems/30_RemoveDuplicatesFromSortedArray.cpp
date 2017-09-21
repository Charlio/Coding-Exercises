class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int num_dup = 0;
        for (int i = 1; i < n; ++i){
            if (nums[i] == nums[i-1]) ++num_dup;
            else nums[i-num_dup] = nums[i];
        }
        nums.erase(nums.end() - num_dup, nums.end());
        return nums.size();
    }
};