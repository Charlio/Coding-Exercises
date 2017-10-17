class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min_idx;
        int low = 0;
        int n = nums.size();
        int high = n-1;
        while(low < high && nums[low] >= nums[high]) {
            int mid = (low+high)/2;
            if(nums[low]>nums[mid])
                high = mid;
            else
                low = mid + 1;
        }
        min_idx = low;
        
        int low_s = 0;
        int high_s = n-1;
        while(low_s <= high_s) {
            int mid_s = (low_s+high_s)/2;
            int true_mid = (mid_s+min_idx)%n;
            if(nums[true_mid] == target)
                return true_mid;
            else if(nums[true_mid] < target){
                low_s = mid_s + 1;
            } else {
                high_s = mid_s - 1;
            }
        }
        return -1;
    }
};