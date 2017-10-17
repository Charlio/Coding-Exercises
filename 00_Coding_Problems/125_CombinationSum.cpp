class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        combSum(res, candidates, vector<int>(), target, 0);
        return res;
    }
    
    void combSum(vector<vector<int>>& res, vector<int>& candidates, vector<int> tmp, int target, int start) {
        if(target < 0) return;
        else if(target == 0) res.push_back(tmp);
        else {
            for(int i = start; i < candidates.size(); i++) {
                tmp.push_back(candidates[i]);
                combSum(res, candidates, tmp, target-candidates[i], i);
                tmp.pop_back();
            }
        }
    } 
};