// link to question - https://leetcode.com/problems/longest-continuous-increasing-subsequence/

class Solution {
public:
    int findLengthOfLCIS(vector<int> a) {
        int n=a.size();
        if(n==0)
            return 0;
        int max=0,c=1;
        for(int i=0;i<n-1;i++){
            if(a[i]<a[i+1]){
                c++;
                if(max<c)
                    max=c;
            }
            else
                c=1;
        }
        if(max<c)
            max=c;
        return max;
    }
};