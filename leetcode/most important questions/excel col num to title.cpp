// link to question - https://leetcode.com/problems/excel-sheet-column-title/submissions/

class Solution {
public:
    string convertToTitle(int n) {
        
        vector<int> b;
        int i,c=0;
        while(n>26){
            i=n%26;
            if(!i){
                b.push_back(26);
                n/=26;
                n--;continue;
            }
            b.push_back(i);
            n/=26;            
        }
        b.push_back(n);
        
        string a;
        for(int i=b.size()-1;i>=0;i--,c++){
            a[c]=(char)(b[i]+64);
        }
        return a;
    }
};