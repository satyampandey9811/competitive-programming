// link to question - https://leetcode.com/problems/maximum-score-words-formed-by-letters/

class Solution {
public:        
    int go(int i, vector<string>& words, vector<int> cnt, vector<int> &score) {
        if(i == words.size()) return 0;
        int ans = 0, res = 0;                

        ans = max(ans, go(i + 1, words, cnt, score));
        
        vector<int> count(26);
        
        for(char c: words[i]) count[c-'a']++;
        for(int j = 0; j < 26; j++) {
            res += count[j] * score[j];
            if(count[j] > cnt[j]) return ans;
        }
        for(int j = 0; j < 26; j++) cnt[j] -= count[j];
        
        ans = max(ans, res + go(i + 1, words, cnt, score));
        
        return ans;
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> cnt(26);        
        for(char c: letters) cnt[c - 'a']++;            
        return go(0, words, cnt, score);
    }
};