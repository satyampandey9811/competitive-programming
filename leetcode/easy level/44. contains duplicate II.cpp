// link to question - https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& a, int k) {
        if(a.size()<2)
            return false;
        for(int i=0;i<a.size()-1;i++){
            for(int j=i+1;j<a.size() and j-i<=k;j++){
                if(a[i]==a[j])
                    return true;
            }
        }
        return false;
    }
};