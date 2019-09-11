// link to question - https://leetcode.com/problems/maximize-distance-to-closest-person/

class Solution {
public:
    int maxDistToClosest(vector<int>& a) {
        int n=a.size();        
        int mx=0,c=0,ans=0;
        int beg,end;
        for(int i=0;i<n;i++){
            if(a[i]){
               beg=i;
               break;
            }
            c++;
        }        
        
        for(int i=n-1;i>=0;i--){
            if(a[i]){
                end=i;
                break;
            }
            mx++;
        }
        
        mx=max(c,mx);
        c=0;
        
        for(;beg<end;beg++){
            if(a[beg]==0){
                c++;
                if(ans<c)
                    ans=c;
            }
            else
                c=0;
        }
        
        ans=(ans+1)/2;
        return max(mx,ans);
    }
};