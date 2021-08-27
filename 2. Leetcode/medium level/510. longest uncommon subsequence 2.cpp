// link to question - https://leetcode.com/problems/longest-uncommon-subsequence-ii/

class Solution {
public:
    bool isSubsequence(string& a, string& b) {
        int i = 0, j = 0, m = a.size(), n = b.size();
        while(i < m and j < n) {
            if(a[i] == b[j]) i++;
            j++;
        }
        return i == m;
    }
    
    int findLUSlength(vector<string>& a) {
        int n = a.size(), ans = -1;
        
        for(int i = 0; i < n; i++) {
            bool f = true;
            for(int j = 0; j < n; j++) {
                if(i != j and isSubsequence(a[i], a[j])) {
                    f = false;
                    break;
                }
            }    
            if(f) ans = max(ans, (int)a[i].size());
        }
        
        return ans;
    }
};