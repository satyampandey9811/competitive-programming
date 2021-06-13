// link to question - https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

class Solution {
public:
    bool makeEqual(vector<string>& a) {
        vector<int> c(26);
        int n = a.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < a[i].size(); j++) {
                c[a[i][j] - 'a']++;
            }
        }
        
        for(int i = 0; i < 26; i++) {
            if(c[i]) {
                if(c[i] % n != 0) return 0;
            }
        }
        
        return 1;
    }
};