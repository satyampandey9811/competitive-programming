// link to question - https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/

class Solution {
public:
    string generateTheString(int n) {
        string ans;        
        int m = 0;
        while(m < n){
            ans += 'a';
            m++;
        }        
        if(n % 2 == 0)
            ans[n - 1] = 'b';
        return ans;
    }
};