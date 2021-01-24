// link to question - https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/

class Solution {
public:
    string maximumTime(string a) {
        if(a[4] == '?') a[4] = '9';
        if(a[3] == '?') a[3] = '5';
        if(a[0] == '1' or a[0] == '0') {
            if(a[1] == '?') a[1] = '9';
        }
        else {
            a[0] = '2';
            if(a[1] == '?') a[1] = '3';
            else if(a[1] > '3' and a[1] <= '9') a[0] = '1';
        }
        return a;
    }
};