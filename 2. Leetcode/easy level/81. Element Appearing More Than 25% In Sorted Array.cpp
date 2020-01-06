// link to question - https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

class Solution {
public:
    int findSpecialInteger(vector<int>& a) {
        int n=a.size();
        map<int,int> m;
        for(int i=0;i<n;i++)
            m[a[i]]++;
        
        int ul=0.25*n;
        for(auto x: m){
            if(x.second>ul)
                return x.first;
        }
        return 0;
    }
};