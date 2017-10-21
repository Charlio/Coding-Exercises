#include <bits/stdc++.h>

using namespace std;

string isBalanced(string s) {
    // Complete this function
    int n = s.length();
    vector<char> stack;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack.push_back(s[i]);
        } else if(s[i] == ')') {
            if(stack.empty() || stack.back() != '(')
                return "NO";
            else
                stack.pop_back();
        } else if(s[i] == ']') {
            if(stack.empty() || stack.back() != '[')
                return "NO";
            else
                stack.pop_back();
        } else if(s[i] == '}') {
            if(stack.empty() || stack.back() != '{')
                return "NO";
            else
                stack.pop_back();
        } else
            return "NO";
    }
    if(stack.empty())
        return "YES";
    else
        return "NO";
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        string result = isBalanced(s);
        cout << result << endl;
    }
    return 0;
}
