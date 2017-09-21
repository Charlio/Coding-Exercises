#include <cmath>

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> counts;
        counts.push_back(0);
        int i, count;
        for(i = 0, count = 0; count < num; ++i){
         int m = pow(2, i);
         for(int j = 0; j < m && count < num; ++j){
             counts.push_back(1+counts[j]);
             ++count;
         }
        }
        return counts;
    }
};