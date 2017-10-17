class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> qu;
        for(int i = 0; i < nums.size(); i++) {
            qu.push(nums[i]);
            if(qu.size() > k)
                qu.pop();
        }
        return qu.top();
    }
};