class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;
        int i = nums.size()-2;
        while(i >= 0) {
            if(nums[i] < nums[i+1]) {
                int j = nums.size()-1;
                while(nums[j] <= nums[i]) {
                    j--;
                }
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
                break;
            }
            i--;
        }
        int low = i+1;
        int high = nums.size()-1;
        while(low < high) {
            int tmp = nums[high];
            nums[high] = nums[low];
            nums[low] = tmp;
            low++;
            high--;
        }
    }
};