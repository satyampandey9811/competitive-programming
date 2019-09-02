// link to question - https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& a) {
        int n=a.size();
        
        int sum=0;
        int c=0,k=0;
        int ans=INT_MAX;
        
        for(int i=0;i<n;){
            sum+=a[i];
            c++;
            if(sum>=s){
                if(ans>=c)
                    ans=c;
                sum=sum-a[k]-a[i];
                k++;
                c-=2;
            }
            else
                i++;
        }
        if(ans==INT_MAX)
            return 0;
        else return ans;
    }
};