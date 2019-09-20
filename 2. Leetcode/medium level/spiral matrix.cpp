// link to question - https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int> ans;
        int m=a.size();
        if(m==0) return {};
        int n=a[0].size();
        int t=0,r=n-1,b=m-1,l=0;
        int dir=0;
        while(l<=r and t<=b){
            if(dir==0){
                for(int i=l;i<=r;i++)
                    ans.push_back(a[t][i]);
                t++;
                dir=1;
            }
            else if(dir==1){
                for(int i=t;i<=b;i++)
                    ans.push_back(a[i][r]);
                r--;
                dir=2;
            }
            else if(dir==2){
                for(int i=r;i>=l;i--)
                    ans.push_back(a[b][i]);
                b--;
                dir=3;
            }
            else if(dir==3){
                for(int i=b;i>=t;i--)
                    ans.push_back(a[i][l]);
                l++;
                dir=0;
            }
        }
        
        return ans;
    }
};