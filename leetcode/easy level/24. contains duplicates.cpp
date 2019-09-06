// link to question - https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& a) {
        
        sort(a.begin(),a.end());
        int i=0,j=i+1;
        while(j<a.size()){
            if(a[i]==a[j])
                return true;
            i++;j++;
        }
        return false;
    }
};