class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        if (n == 0) return ans;
        int count1 = 1;
        int count2 = 0;
        int major1 = nums[0];
        int major2 = nums[0];
        for (int i = 1; i < n; i++){
            if (major1 == nums[i]){
                count1++;
            } else if (major2 == nums[i]){
                count2++;
            } else if (count1 == 0){
                count1++;
                major1 = nums[i];
            } else if (count2 == 0){
                count2++;
                major2 = nums[i];
            } else {
                count1--;
                count2--;
            }
        }
        if (std::count(nums.begin(), nums.end(), major1) > n/3) ans.push_back(major1);
        if (major1 != major2 && std::count(nums.begin(), nums.end(), major2) > n/3) ans.push_back(major2);
        return ans;
    }
};