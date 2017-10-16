class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 0) return "";
        int max_len = 1;
        string max_pstr = s.substr(0, 1);
        for(int i = 0; i < 2*n-3;i++) {
            int left;
            int right;
            if(i % 2 == 0) {
                left = i/2;
                right = i/2 + 1;
            } else {
                left = (i-1)/2;
                right = (i+3)/2;
            }
            while(s[left] == s[right] && left >= 0 && right < n) {
                left--;
                right++;
            }
            if(max_len < right-left-1) {
                max_len = right-left-1;
                max_pstr = s.substr(left+1, right-left-1);
            }
        }
        return max_pstr;
    }
};