class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> dict = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int n = s.length();
        
        int ans = dict[s[n-1]];
        
        for(int i = s.length()-2; i >= 0; i--) {
            if(dict[s[i]] < dict[s[i+1]])
                ans -= dict[s[i]];
            else
                ans += dict[s[i]];
        }
        
        return ans;
        
    }
};