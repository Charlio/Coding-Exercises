class Solution {
public:
    int romanToInt(string s) {
        // I: 1; V: 5; X: 10; L: 50; C: 100; D: 500; M: 1000
        // IV: 4; IX: 9; XL: 40; XC: 90; CD: 400; CM: 900
        int n = s.length();
        if(n == 0) return 0;
        int i = 0;
        int ans = 0;
        while(i < n) {
            switch(s[i]) {
                case 'I':
                    if(i+1 < n) {
                        if(s[i+1] == 'V') {
                            ans += 4;
                            i += 2;
                        } else if(s[i+1] == 'X') {
                            ans += 9;
                            i += 2;
                        } else {
                            ans += 1;
                            i++;
                        }
                    } else {
                        ans += 1;
                        i++;
                    }
                    break;
                case 'V':
                    ans += 5;
                    i++;
                    break;
                case 'X':
                    if(i+1 < n){
                        if(s[i+1] == 'L') {
                            ans += 40;
                            i += 2;
                        } else if(s[i+1] == 'C') {
                            ans += 90;
                            i += 2;
                        } else {
                            ans += 10;
                            i++;
                        }
                    } else {
                            ans += 10;
                            i++;
                        }
                    break;
                case 'L':
                    ans += 50;
                    i++;
                    break;
                case 'C':
                    if(i+1 < n) {
                        if(s[i+1] == 'D') {
                            ans += 400;
                            i += 2;
                        } else if(s[i+1] == 'M') {
                            ans += 900;
                            i += 2;
                        } else {
                            ans += 100;
                            i++;
                        }
                    } else {
                        ans += 100;
                        i++;
                    }
                    break;                    
                case 'D':
                    ans += 500;
                    i++;
                    break;
                case 'M':
                    ans += 1000;
                    i++;
                    break;
                default:
                    return 0;
            }
        };
        return ans;
    }
};