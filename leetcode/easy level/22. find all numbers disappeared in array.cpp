// link to question - https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
        
        int n=a.size();
        vector<int> b(n);
        
        for(int i=0;i<n;i++){
            b[a[i]-1]=1;
        }
        int ct=0;
        for(int i=0;i<n;i++){
            if(!b[i])
                b[ct++]=i+1;
        }
        while(b.size()>ct)
            b.pop_back();
        return b;
    }
};