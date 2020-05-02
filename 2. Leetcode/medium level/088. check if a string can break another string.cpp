// link to question - https://leetcode.com/problems/check-if-a-string-can-break-another-string/

class Solution {
public:
    bool checkIfCanBreak(string a, string b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool flag = 1;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] < b[i]){
                flag = 0;
                break;
            }
        }
        if(flag) return 1;
        flag = 1;
        for(int i = 0; i < a.size(); i++) {
            if(b[i] < a[i]){
                flag = 0;
                break;
            }
        }
        return flag;
    }
};