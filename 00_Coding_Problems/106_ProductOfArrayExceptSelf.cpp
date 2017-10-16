class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prods(nums.size());
        if(n == 0) return prods;
        prods[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prods[i] = prods[i-1]*nums[i];
        }
        int prod_r = 1;
        for(int i = n-1; i > 0; i--) {
            prods[i] = prod_r * prods[i-1];
            prod_r *= nums[i];
        }
        prods[0] = prod_r;
        return prods;
    }
};