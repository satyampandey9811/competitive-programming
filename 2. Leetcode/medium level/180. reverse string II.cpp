// link to question - https://leetcode.com/problems/reverse-string-ii/

class Solution {
public:
    string reverseStr(string a, int k) {
        
        int b=0,c=0;
        for(int i=0;i<a.size();){
            if(a.size()-c<k){
                reverse(a.begin()+c,a.end());
                return a;
            }
            if(b==k-1){
                reverse(a.begin()+c,a.begin()+i+1);
                b=0;i=c+2*k;c=i;continue;
            }
            b++;i++;
        }        
        
        return a;
    }
};