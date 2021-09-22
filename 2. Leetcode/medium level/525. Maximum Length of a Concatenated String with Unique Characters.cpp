// link to question - https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution {
public:
    int maxLength(vector<string>& a) {
        int n = a.size();
        int ans = 0;
        
        for(int i = 0; i < (1 << n); i++) {
            int c = 0, v = 0;
            bool f = true;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    for(int k = 0; k < (int)a[j].size(); k++) {
                        if(v & (1 << (a[j][k] - 'a'))) {
                            f = false;
                            break;
                        }
                        v |= (1 << (a[j][k] - 'a'));
                        c++;
                    }
                    if(!f) break;
                }
            }
            if(f) ans = max(ans, c);
        }
                           
        return ans;
    }
};