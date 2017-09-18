class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;
        int major = nums[0];
        int count = 1;
        for (int i = 1; i < n; i++){
            if (count == 0){
                count++;
                major = nums[i];
            } else if (major == nums[i]){
                count++;
            } else {
                count--;
            }
        }
        return major;
    }
};