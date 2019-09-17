// link to question - https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        string c;
        int d=0;
        int m=a.size(),n=b.size();
        
        while(n < m) b = '0' + b, n++;
        while(m < n) a = '0' + a, m++;
        
        for(int i=m-1,j=n-1;i>=0 and j>=0;i--,j--){
            int x=a[i]-'0'+ b[j]-'0'+d;
            if(x==2){
                c+='0';
                d=1;
            }
            else if(x==3){
                c+='1';
                d=1;
            }
            else{
                c+=to_string(x);
                d=0;
            }
        }
        if(d)
            c+=to_string(1);
        reverse(c.begin(),c.end());
        return c;
    }
};