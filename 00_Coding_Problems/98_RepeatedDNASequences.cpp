class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> repeat;
        if(s.length() < 10)
            return repeat;
        unordered_map<string, int> dna_map;
        for(int i = 0; i < s.length() - 9; i++) {
            if(dna_map.find(s.substr(i, 10)) == dna_map.end())
               dna_map[s.substr(i, 10)] = 1;
            else
                dna_map[s.substr(i, 10)]++;
        }
        for(unordered_map<string, int>::iterator it = dna_map.begin(); it != dna_map.end(); it++) {
            if(it->second > 1)
                repeat.push_back(it->first);
        }
        return repeat;
    }
};