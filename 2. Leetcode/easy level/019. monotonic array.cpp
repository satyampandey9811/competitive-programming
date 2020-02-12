// link to question - https://leetcode.com/problems/monotonic-array/

class Solution {
public:
    bool isMonotonic(vector<int>& a) {
        int n=a.size();
        int c=0;
        for(int i=1;i<n;i++){
            if(a[i]>=a[i-1])
                c++;
            else 
                break;
        }
        if(c==n-1)
            return true;
        c=0;
        for(int i=1;i<n;i++){
            if(a[i]<=a[i-1])
                c++;
            else 
                break;
        }
        if(c==n-1)
            return true;
        else 
            return false;
        
    }
};