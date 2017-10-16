class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> dig_chars;
        dig_chars['1'] = "";
        dig_chars['2'] = "abc";
        dig_chars['3'] = "def";
        dig_chars['4'] = "ghi";
        dig_chars['5'] = "jkl";
        dig_chars['6'] = "mno";
        dig_chars['7'] = "pqrs";
        dig_chars['8'] = "tuv";
        dig_chars['9'] = "wxyz";
        dig_chars['0'] = "";
        
        vector<string> combo;
        int n = digits.length();
        if(n == 0) {
            return combo;
        }
        
        char dig = digits[0];
        vector<string> prev_combo = letterCombinations(digits.substr(1, n-1));
        for(int i = 0; i < dig_chars[dig].length(); i++) {
            if(prev_combo.size() == 0) {
                combo.push_back(dig_chars[dig].substr(i,1));
            } else {
                for(int j = 0; j < prev_combo.size(); j++) {
                    combo.push_back(dig_chars[dig][i]+prev_combo[j]);
                }
            }
        }
        return combo;
    }
};