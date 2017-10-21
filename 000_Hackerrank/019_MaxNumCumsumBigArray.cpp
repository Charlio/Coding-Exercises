#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    
    long* nums = new long[n+1]();
    for(int i = 0; i < n+1; i++)
        nums[i] = 0;
    unsigned long max_num = 0;
    
    for(int a0 = 0; a0 < m; a0++){
        int a;
        int b;
        unsigned int k;
        cin >> a >> b >> k;
        nums[a-1] += k;
        nums[b] -= k;
    }
    
    unsigned long cumsum = 0;
    for(int i = 0; i < n; i++) {
        cumsum += nums[i];
        max_num = max(max_num, cumsum);
    }
    
    cout << max_num << endl;
    
    return 0;
}
