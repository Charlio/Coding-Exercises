class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        if(n < 2) return n;
        int count = 0;
        for(int i = 0; i < 2*n-1; i++) {
            if(i%2==0) {
                int diff = 0;
                while(i/2-diff>=0 && i/2+diff<n && s[i/2-diff] == s[i/2+diff]) {
                    count++;
                    diff++;
                }
            } else {
                int diff = 0;
                while((i-1)/2-diff>=0 && (i+1)/2+diff<n && s[(i-1)/2-diff] == s[(i+1)/2+diff]) {
                    count++;
                    diff++;
                }
            }
        }
        return count;
    }
};