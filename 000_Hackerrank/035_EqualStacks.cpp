#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n1;
    int n2;
    int n3;
    vector<int> ht(3, 0);
    cin >> n1 >> n2 >> n3;
    vector<deque<int> > h(3, deque<int>());
    for(int h1_i = 0;h1_i < n1;h1_i++){
        int tmp;
        cin >> tmp;
        h[0].push_front(tmp);
        ht[0] += tmp;
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
        int tmp;
        cin >> tmp;
        h[1].push_front(tmp);
        ht[1] += tmp;
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
        int tmp;
        cin >> tmp;
        h[2].push_front(tmp);
        ht[2] += tmp;
    }
    
    int curr_max = max(ht[0], max(ht[1], ht[2]));
    while((ht[0] != curr_max || ht[1] != curr_max || ht[2] != curr_max)  ) {
        for(int i = 0; i < 3; i++) {
            if(ht[i] == curr_max) {
                ht[i] -= h[i].back();
                h[i].pop_back();
                curr_max = max(ht[0], max(ht[1], ht[2]));
                break;
            }
        }
    }
    
    cout << curr_max << endl;
    
    
    return 0;
}
