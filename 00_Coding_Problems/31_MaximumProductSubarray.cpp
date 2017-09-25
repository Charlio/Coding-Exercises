class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return -1;
        vector<int>::iterator it;
        int max_so_far = INT_MIN;
        int max_ending = 1;
        int min_ending = 1;
        for(it = nums.begin(); it != nums.end(); ++it){
            if (*it < 0) swap(max_ending, min_ending);
            max_ending = max(max_ending*(*it), *it);
            min_ending = min(min_ending*(*it), *it);
            max_so_far = max(max_so_far, max_ending);
        }
        return max_so_far;
    }
};