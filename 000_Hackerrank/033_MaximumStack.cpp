#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> stack;
    vector<int> max_stack;
    for(int i = 0; i < n; i++) {
        int q;
        cin >> q;
        if(q == 1) {
            int val;
            cin >> val;
            stack.push_back(val);
            if(max_stack.empty() || val >= max_stack.back())
                max_stack.push_back(val);
        } else if(q == 2) {
            if(!stack.empty()) {
                if(stack.back() == max_stack.back())
                    max_stack.pop_back();
                stack.pop_back();
            }
        } else if(q == 3) {
            if(!max_stack.empty())
                cout << max_stack.back() << endl;
        }
    }
    return 0;
}
