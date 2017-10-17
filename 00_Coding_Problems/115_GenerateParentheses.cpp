class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string> > pLists(n+1, vector<string>());
        pLists[0].push_back("");
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= i-1; j++) {
                for(string str1 : pLists[j]) {
                    for(string str2 : pLists[i-1-j]) {
                        string tmp = "("+str1+")"+str2;
                        pLists[i].push_back(tmp);
                    }
                }
            }
        }
        return pLists.back();
    }
};