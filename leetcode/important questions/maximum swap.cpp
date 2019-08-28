// link to question - https://leetcode.com/problems/maximum-swap/

class Solution {
public:
    int maximumSwap(int n) {
        
        string a=to_string(n);
        string b=a;
        sort(b.begin(),b.end(),greater<int>());
        for(int i=0;i<b.size();i++){
            if(b[i]!=a[i]){
                int j;
                for(j=a.size()-1;j>=0;j--){
                    if(b[i]==a[j])
                        break;
                }
                swap(a[i],a[j]);
                break;
            }
        }
        return stoi(a);
        
    }
};