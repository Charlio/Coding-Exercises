class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums_1;
        for(int i = 0; i < nums1.size(); i++) {
            nums_1.insert(nums1[i]);
        }
        unordered_set<int> intersection;
        for(int i = 0; i < nums2.size(); i++) {
            if(nums_1.find(nums2[i]) != nums_1.end()) {
                intersection.insert(nums2[i]);
            }
        }
        return vector<int>(intersection.begin(), intersection.end());
    }
};