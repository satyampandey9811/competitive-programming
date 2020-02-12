// link to question - https://leetcode.com/problems/can-place-flowers/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int k) {
        int n=a.size(); 
        auto it=find(a.begin(),a.end(),1);
        if(it==a.end()){
            k=k-(n+1)/2;
            if(k<=0)
                return true;
            else
                return false;
        }
               
        int c=0;
        int beg,end;
        for(int i=0;i<n;i++){
            if(a[i]){
               beg=i;
               break;
            }
            c++;
        }     
        
        k=k-(c/2);
        if(k<=0)
            return true;
        c=0;
        
        for(int i=n-1;i>=0;i--){
            if(a[i]){
                end=i;
                break;
            }
            c++;
        }
        
        k=k-(c/2);
        if(k<=0)
            return true;
        c=0;        
        
        for(;beg<=end;beg++){
            if(a[beg]==0){
                c++;                
            }
            else{
                k=k-(c-1)/2;
                if(k<=0)
                    return true;
                c=0;
            }
        }
        return false;
    }
};