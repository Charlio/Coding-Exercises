class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() < 2) return;
        int low = 0;
        while(nums[low] == 0)
            low++;
        int high = nums.size()-1;
        while(nums[high] == 2)
            high--;
        int i = low; 
        while(i <= high) {
            if(nums[i] == 0 && i > low) {
                int tmp = nums[low];
                nums[low++] = 0;
                nums[i] = tmp;
            } else if(nums[i] == 2 && i < high) {
                int tmp = nums[high];
                nums[high--] = 2;
                nums[i] = tmp;
            } else {
                i++;
            }
        }
    }
};