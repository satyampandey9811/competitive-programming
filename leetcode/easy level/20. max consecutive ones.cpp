// link to question - https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int n=a.size();
        int c=0,max=0;
        for(int i=0;i<n;i++){
            if(a[i]){
                c++;
            }
            if(max<c)
                max=c;
            if(!a[i])
                c=0;
        }
        return max;
    }
};