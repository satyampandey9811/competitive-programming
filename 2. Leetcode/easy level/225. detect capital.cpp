// link to question - https://leetcode.com/problems/detect-capital/

class Solution {
public:
    bool detectCapitalUse(string a) {
        int n=a.size();
        if(a[0]>='A' and a[0]<='Z'){
            int c=0,s=0;
            for(int i=1;i<n;i++){
                if(a[i]>='A' and a[i]<='Z')
                    c++;
                else
                    s++;
            }
            if(c==n-1 or s==n-1)
                return true;
            else
                return false;
        }
        
        else{
            for(int i=1;i<n;i++){
                if(a[i]>='A' and a[i]<='Z')
                    return false;
            }           
        }
        return true;
    }
};