class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> primes(n, true);
        primes[0] = primes[1] = false;
        int count = 1;
        double root = sqrt(n);
        for (int i = 3; i < n; i += 2){
            if (primes[i]) {
                ++count;
                // << i << ' ';
                if (i > root) continue;
                else {
                    for (int j = i*i; j < n; j+=i)
                        primes[j] = false;
                }
            }
        }
        //cout << endl;
        return count;
    }
};