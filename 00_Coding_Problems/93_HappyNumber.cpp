class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> nums;
        nums.insert(n);
        int cur_num = n;
        while(cur_num != 1) {
            string s_num = to_string(cur_num);
            cur_num = 0;
            for(char ch:s_num) {
                cur_num += (ch-'0')*(ch-'0');
            }
            if(nums.find(cur_num) != nums.end()) {
                return false;
            } else {
                nums.insert(cur_num);
            }
        }
        return true;
        
    }
};