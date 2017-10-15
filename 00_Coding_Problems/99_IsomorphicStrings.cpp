class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        unordered_map<char, char> match;
        unordered_set<char> used_in_t;
        for(int i = 0; i < n; i++) {
            if(match.find(s[i]) != match.end()) {
                if(match[s[i]] == t[i])
                    continue;
                else
                    return false;
            } else {
                if(used_in_t.find(t[i]) != used_in_t.end())
                    return false;
                else {
                    match[s[i]] = t[i];
                    used_in_t.insert(t[i]);
                }
            }
        }
        return true;
    }
};