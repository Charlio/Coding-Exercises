class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        
        int imin = 0, imax = m;
        while (imin <= imax){
            int i = (imin + imax) / 2;
            int j = (m + n + 1) / 2 - i;
            
            if (i != 0 && nums1[i-1] > nums2[j]){
                imax = i-1;
            } else if (i != m && nums2[j-1] > nums1[i]){
                imin = i+1;
            } else {
                int left_max;
                if (i == 0) left_max = nums2[j-1];
                else if (j == 0) left_max = nums1[i-1];
                else left_max = max(nums1[i-1], nums2[j-1]);
                
                if ((m + n) % 2 == 1){
                    return left_max;    
                } else {
                    int right_min;
                    if (i == m) right_min = nums2[j];
                    else if (j == n) right_min = nums1[i];
                    else right_min = min(nums1[i], nums2[j]);
                    return (left_max + right_min) / 2.0;
                }
            }
        }
        return -1;
    }
};