// link to question - https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/

class Solution {
public:
    map<char, pair<int, int>> m = {{'A', {0, 0}}, {'B', {0, 1}}, {'C', {0, 2}}, {'D', {0, 3}}, {'E', {0, 4}}, {'F', {0, 5}}, {'G', {1, 0}}, {'H', {1, 1}}, {'I', {1, 2}}, {'J', {1, 3}}, {'K', {1, 4}}, {'L', {1, 5}}, {'M', {2, 0}}, {'N', {2, 1}}, {'O', {2, 2}}, {'P', {2, 3}}, {'Q', {2, 4}}, {'R', {2, 5}}, {'S', {3, 0}}, {'T', {3, 1}}, {'U', {3, 2}}, {'V', {3, 3}}, {'W', {3, 4}}, {'X', {3, 5}}, {'Y', {4, 0}}, {'Z', {4, 1}}};
    
    int n;
    int dp[26][26][301];
    
    int go(char c, char d, int i, string &word) {
        if(i == n) return 0;
        
        int &ans = dp[c-'A'][d-'A'][i];
        if(ans != -1) return ans;
        
        ans = INT_MAX;
        char l = word[i];
        int ffx = m[c].first, ffy = m[c].second;
        int sfx = m[d].first, sfy = m[d].second;
        int lx = m[l].first, ly = m[l].second;
        
        ans = min(ans, abs(ffx - lx) + abs(ffy - ly) + go(l, d, i + 1, word));
        ans = min(ans, abs(sfx - lx) + abs(sfy - ly) + go(c, l, i + 1, word));

        return ans;
    }
    
    int minimumDistance(string word) {
        int ans = INT_MAX;
        n = word.size();
        memset(dp, -1, sizeof dp);
        
        for(char c = 'A'; c <= 'Z'; c++) {
            for(char d = c + 1; d <= 'Z'; d++) {
                ans = min(ans, go(c, d, 0, word));
            }
        }
        
        return ans;
    }
};