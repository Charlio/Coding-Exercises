class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> res;
        sort(people.begin(), people.end(), [](pair<int, int>& p1, pair<int, int>& p2){return p1.first > p2.first || p1.first == p2.first && p1.second < p2.second;});
        for(int i = 0; i < people.size(); i++) {
            res.insert(res.begin() + people[i].second, people[i]);
        }
        return res;
    }
};