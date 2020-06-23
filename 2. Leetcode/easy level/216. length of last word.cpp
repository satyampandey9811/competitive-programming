// link to question - https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string a) {
        int n=a.size(),c=0;
        for(int i=n-1;i>=0;i--){
            if(c==0 and a[i]==' '){
                continue;
            }   
            if(a[i]==' ')
                break;
            c++;            
        }
        return c;
    }
};