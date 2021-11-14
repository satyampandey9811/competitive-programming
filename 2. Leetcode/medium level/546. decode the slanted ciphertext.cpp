// link to question - https://leetcode.com/problems/decode-the-slanted-ciphertext/

class Solution {
public:
    string decodeCiphertext(string a, int r) {
        int n = a.size();
        int c = n / r;
        vector<vector<char>> b(r, vector<char>(c));
        
        int i = 0, j = 0, ct = 0;
        
        while(ct < n) {
            b[i][j++] = a[ct++];
            if(j == c) i++, j = 0;
        }
        
        string ans;
        
        for(int i = 0; i < c; i++) {
            int col = i;
            for(int j = 0; j < r; j++) {
                ans += b[j][col++];
                if(col == c) break;
            }
        }
        while(ans.size() and ans.back() == ' ') ans.pop_back();
        return ans;
    }
};