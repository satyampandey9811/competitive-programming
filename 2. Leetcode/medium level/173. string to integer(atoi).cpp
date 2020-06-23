// link to question - https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string a) {
        
        int n=a.size(),c=0,d=0,e=0,f=0,g=0,h=0;
        if(n==0)
            return 0;
        for(int i=0;i<n-1;i++){
            if(a[i]>='1' and a[i]<='9')
                break;
            if(a[i]=='-' and a[i+1]=='-')
                return 0;
            else if(a[i]=='-' and a[i+1]=='+')
                return 0;
            else if(a[i]=='+' and a[i+1]=='-')
                return 0;
            else if(a[i]=='+' and a[i+1]=='+')
                return 0;
            else if(a[i]=='0' and a[i+1]=='-')
                return 0;
            else if(a[i]=='0' and a[i+1]=='+')
                return 0;
            else if(a[i]=='+' and a[i+1]==' ')
                return 0;
            else if(a[i]=='-' and a[i+1]==' ')
                return 0;
            else if(a[i]=='0' and a[i+1]==' ')
                return 0;
        }
        string b;
        for(int i=0;i<n;i++){
            if(a[i]=='-') g=1;
            if(a[i]=='+') h=1;
            if(c>0 and a[i]==' ')
                break;
            else if(c==0 and a[i]==' ')
                continue;
            else if(f==0 and a[i]=='0')
                continue;
            else if(e>0 and (a[i]=='-' and a[i]=='+'))
                break;
            else if(a[i]=='-' or a[i]=='+' or (a[i]>='0' and a[i]<='9')){
                b+=a[i];c=1;d++;e++;
                if(a[i]=='-' or a[i]=='+')
                    f=0;
                else 
                    f=1;
                if(d>11){
                    if(g)
                        return INT_MIN;
                    else 
                        return INT_MAX;
                }
            }
            else
                break;
        }
        if(b.size()==0 or (b.size()==1 and (b[0]=='-' or b[0]=='+')))
            return 0;
        long long int p=stoll(b);
        if(p<INT_MIN )
            return INT_MIN;
        else if(p>INT_MAX)
            return INT_MAX;
        else
            return p;
    }
};