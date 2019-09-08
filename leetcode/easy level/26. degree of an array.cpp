// link to question - https://leetcode.com/problems/degree-of-an-array/

class Solution {
public:
    int findShortestSubArray(vector<int>& a) {
        
        int n=a.size();
        if(n==1)
            return 1;
        int ma=0;
        for(int i=0;i<n;i++){
            if(ma<a[i])
                ma=a[i];
        }
        vector<vector<int>> b(ma+1,vector<int>(3));
        for(int i=0;i<n;i++){
            int x=a[i];            
            b[x][0]++;
            if(b[x][0]==1)
                b[x][1]=i;
            else if(b[x][0]>1)
                b[x][2]=i;
        }
        int max=0,d,e,f;
        for(int i=0;i<=ma;i++){
            d=b[i][0];
            if(max<d){
                max=d;
                e=b[i][1];
                f=b[i][2];
            }
            else if(max==d and (f-e>b[i][2]-b[i][1])){
                e=b[i][1];
                f=b[i][2];
            }
        }
        if(f==0)
            return 1;
        return f-e+1;
    }
};