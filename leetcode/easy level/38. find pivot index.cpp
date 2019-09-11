// link to question - https://leetcode.com/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int b=0;
        int sum=accumulate(a.begin(),a.end(),0);
        for(int i=0;i<a.size();i++){                        
           //c=accumulate(a.begin()+i+1,a.end(),0);  
           if(b==sum-b-a[i])
                return i;
            b+=a[i];
        }
        return -1;
    }
};