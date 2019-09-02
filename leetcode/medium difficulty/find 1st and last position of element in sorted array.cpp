// link to question - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
        auto it=find(a.begin(),a.end(),t);
        if(it==a.end())
            return {-1,-1};
        else
            return {lower_bound(a.begin(),a.end(),t)-a.begin(),upper_bound(a.begin(),a.end(),t)-a.begin()-1};
    }
};