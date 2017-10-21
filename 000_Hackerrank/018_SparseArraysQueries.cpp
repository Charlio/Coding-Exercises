#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    unordered_map<string, int> str_count;
    for(int i = 0; i < n; i++) {
        string tmp_str;
        cin >> tmp_str;
        if(str_count.find(tmp_str) == str_count.end()){
            str_count.insert(pair<string, int>(tmp_str, 1));
        } else {
            str_count[tmp_str]++;
        }
    }
    
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        string tmp_str;
        cin >> tmp_str;
        if(str_count.find(tmp_str) == str_count.end()) {
            cout << 0 << endl;
        } else {
            cout << str_count[tmp_str] << endl;
        }
    }
    
    return 0;
}
