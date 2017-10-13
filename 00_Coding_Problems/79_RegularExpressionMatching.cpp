class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.length() == 0)
            return s.length() == 0;
        bool curr_match = s.length()!=0 && (s[0] == p[0] || p[0] == '.');
        if(p.length() > 1 && p[1] == '*')
            return isMatch(s, p.substr(2)) || (curr_match && isMatch(s.substr(1), p));
        else
            return curr_match && isMatch(s.substr(1), p.substr(1));
    }
};