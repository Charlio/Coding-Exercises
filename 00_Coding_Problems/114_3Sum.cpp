class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        int n = nums.size();
        if(n < 3) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++) {
            if(i == 0 || nums[i] != nums[i-1]) {
                int tmp = 0 - nums[i];
                int low = i+1;
                int high = n-1;
                while(low < high) {
                    if(nums[low]+nums[high] == tmp) {
                        vector<int> triple = {nums[i], nums[low], nums[high]};
                        res.push_back(triple);
                        while(low < high && nums[low] == nums[low+1]) low++;
                        while(high > low && nums[high] == nums[high-1]) high--;
                        low++;
                        high--;
                    } else if(nums[low]+nums[high] < tmp) {
                        while(low < high && nums[low] == nums[low+1]) low++;
                        low++;
                    } else {
                        while(high > low && nums[high] == nums[high-1]) high--;
                        high--;
                    }
                }
            }
        }
        return res;
    }
};