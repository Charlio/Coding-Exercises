class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        int left = 0;
        int right = n-1;
        bool leftFound = false;
        bool rightFound = false;
        while(left <= right && (!leftFound || !rightFound)) {
            if(!leftFound && nums[left] == my_min(nums, left, right)) {
                left++;
            } else {
                leftFound = true;
            }
            if(!rightFound && nums[right] == my_max(nums, left, right)) {
                right--;
            } else {
                rightFound = true;
            }
        }
        return right-left+1;
    }
    
    int my_min(vector<int>& nums, int left, int right) {
        int min_val = INT_MAX;
        int i = left;
        while(i<=right) {
            min_val = min(min_val, nums[i++]);
        }
        return min_val;
    }
    
    int my_max(vector<int>& nums, int left, int right) {
        int max_val = INT_MIN;
        int i = left;
        while(i<=right) {
            max_val = max(max_val, nums[i++]);
        }
        return max_val;
    }
    
};