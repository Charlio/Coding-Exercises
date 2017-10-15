class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > anagrams;
        for(int i = 0; i < strs.size(); i++) {
            string pattern = strs[i];
            sort(pattern.begin(), pattern.end());
            if(anagrams.find(pattern) == anagrams.end())
                anagrams[pattern] = vector<string> {strs[i]};
            else
                anagrams[pattern].push_back(strs[i]);
        }
        vector<vector<string> > groups;
        for(unordered_map<string, vector<string> >::iterator it = anagrams.begin(); it != anagrams.end(); it++) {
            groups.push_back(it->second);
        }
        return groups;
    }
};