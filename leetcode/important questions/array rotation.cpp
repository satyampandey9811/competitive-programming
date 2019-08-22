// link to question - https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& a, int k) {
        
        if(k%a.size()==0)
            return ;
        reverse(a.begin(),a.end());
        k=k%a.size();
        reverse(a.begin(),a.begin()+k);
        reverse(a.begin()+k,a.end());
    }
};