// link to question - https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/

class Solution {
public:
    int maxDiff(int num) {
        int a, b;
        string x = to_string(num), y = x;
        char p;
        int t = x.size();
        
        for(int i = 0; i < x.size(); i++) {
            if(x[i] != '9') {
                p = x[i];
                t = i;
                break;
            }
        }
        for(int i = t; i < x.size(); i++) {
            if(x[i] == p) x[i] = '9';
        }
        t = y.size();
        for(int i = 0; i < y.size(); i++) {
            if(i == 0 and y[i] != '1') {
                p = y[i];                
                t = i;
                break;
            }
            else if(y[i] > '1') {
                p = y[i];
                t = i;
                break;
            }
        }
        for(int i = t; i < y.size(); i++) {
            if(y[i] == p and t == 0) y[i] = '1';
            else if(y[i] == p) y[i] = '0';
        }        
        a = stoi(x), b = stoi(y);
        return a - b;
    }
};