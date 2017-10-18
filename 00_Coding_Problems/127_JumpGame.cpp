class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return true;
        vector<int> res(n, 0);
        res[n-1] = 1;
        for(int i = n-2; i >= 0; i--) {
            for(int j = min(n-1, i+nums[i]); j >= i+1; j--) {
                if(res[j] == 1) {
                    res[i] = 1;
                    break;
                }
            }
        }
        return res[0];
    }
};