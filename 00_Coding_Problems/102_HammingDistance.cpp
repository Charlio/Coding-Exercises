class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x^y;
        int dist = 0;
        while(n != 0) {
            dist += n%2;
            n = n >> 1;
        }
        return dist;
    }
};