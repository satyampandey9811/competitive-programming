// link to question - https://leetcode.com/problems/fair-candy-swap/

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        vector<int> c(2);
        int m=a.size(),n=b.size();
        long long int suma=0,sumb=0;
        
        for(int i=0;i<m;i++)
            suma+=a[i];        
        
        for(int j=0;j<n;j++)
            sumb+=b[j];
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        for(int i=0;i<m;i++){
            int x=0,y=n-1;
            int z=a[i]+(sumb-suma)/2;
            while(x<=y){
                int mid=(x+y)/2;
                if(b[mid]==z){
                    c[0]=a[i];c[1]=z;
                    return c;
                }
                else if(b[mid]>z)
                    y=mid-1;
                else 
                    x=mid+1;
            }
            
        } 
        return c;
    }
};