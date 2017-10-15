class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> keys;
        keys.push_back("qwertyuiopQWERTYUIOP");
        keys.push_back("asdfghjklASDFGHJKL");
        keys.push_back("zxcvbnmZXCVBNM");
        vector<string> valid_inputs;
        for(int i = 0; i < words.size(); i++) {
            int row;
            for(int k = 0; k < 3; k++) {
                if(keys[k].find(words[i][0]) != string::npos)
                    row = k;
            }
            int valid = 1;
            for(int j = 1; j < words[i].size(); j++) {
                if(keys[row].find(words[i][j]) == string::npos)
                    valid = 0;
            }
            if(valid == 1)
                valid_inputs.push_back(words[i]);
        }
        return valid_inputs;
    }
};