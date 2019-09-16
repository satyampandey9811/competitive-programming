// link to question - https://leetcode.com/problems/excel-sheet-column-number/

class Solution {
public:
    int titleToNumber(string s) {
        long long int x=0;
        for(int i=0;i<s.size();i++){
            x=(x*26) + s[i]-'A'+1;           
        }
        return x;
    }
};