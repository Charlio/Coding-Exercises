class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0; 
        
        int max_end = 0;
        int max_so_far = 0;
        vector<char> table;
        
        for (int i = 0; i < n; ++i){
            vector<char>::iterator it = find(table.begin(), table.end(), s[i]);
            if (it == table.end()){
                max_end += 1;
            } else {
                table.erase(table.begin(), it+1);
                max_end = table.size() + 1;
            }
            table.push_back(s[i]);
            max_so_far = max(max_so_far, max_end);
        }
        return max_so_far;
    }
};