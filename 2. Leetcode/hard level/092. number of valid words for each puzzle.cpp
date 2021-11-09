// link to question - https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int wlen = words.size();
        int n = puzzles.size();
        map<int, int> m;
        vector<int> ans(n);
        
        for(int i = 0; i < wlen; i++) {
            int mask = 0;
            for(int j = 0; j < words[i].size(); j++) {
                mask |= (1 << (words[i][j] - 'a'));
            }
            m[mask]++;
        }
        
        for(int i = 0; i < n; i++) {
            string s = puzzles[i];
            int count = 0;
            
            for(int j = 0; j < (1 << 7); j++) {
                int mask = 1 << (s[0] - 'a');
                for(int k = 1; k < 7; k++) {
                    if(j & (1 << k)) {
                        mask |= (1 << (s[k] - 'a'));
                    }
                }
                count += m[mask];
            }
            
            ans[i] = count / 2;
        }
        
        return ans;
    }
};