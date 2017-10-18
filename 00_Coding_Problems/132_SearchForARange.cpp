class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.size() == 0) return res;
        
        int low = 0;
        int high = nums.size()-1;
        
        while(low < high) {
            int mid = (low+high)/2 + 1;
            if(nums[mid] <= target) {
                low = mid;
            } else {
                high = mid-1;
            }
        }        
        
        if(nums[high] != target) return res;
        else res[1] = high;
        
        low = 0;
        while(low < high) {
            int mid = (low+high)/2;
            if(nums[mid] >= target) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        
        res[0] = low;
    
        return res; 
    }
};