class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return nums[0];
        int slow = nums[0];
        int fast = nums[nums[0]];
        int ptr = 0;
        while(fast != slow) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(ptr != slow) {
            slow = nums[slow];
            ptr = nums[ptr];
        }
        return ptr;
    }
};