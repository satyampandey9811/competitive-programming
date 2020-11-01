// link to question - https://leetcode.com/problems/delete-columns-to-make-sorted/

class Solution {
public:
    int minDeletionSize(vector<string>& a) {
        int ans = 0;
        int n = a[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < a.size(); j++) {
                if(a[j][i] < a[j-1][i]) {
                    ans++;
                    break;
                }
            }
        }
        
        return ans;
    }
};