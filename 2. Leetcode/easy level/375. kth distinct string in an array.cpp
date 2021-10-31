// link to question - https://leetcode.com/problems/kth-distinct-string-in-an-array/

class Solution {
public:
    string kthDistinct(vector<string>& a, int k) {
        map<string, int> m;
        int n = a.size(), ct = 0;
        
        for(int i = 0; i < n; i++) {
            m[a[i]]++;
        }
        
        for(int i = 0; i < n; i++) {
            if(m[a[i]] == 1) {
                ct++;
                if(ct == k) return a[i];
            }
        }
        
        return "";
    }
};