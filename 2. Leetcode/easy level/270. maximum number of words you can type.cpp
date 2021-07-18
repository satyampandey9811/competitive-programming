// link to question - https://leetcode.com/problems/maximum-number-of-words-you-can-type/

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> present(26);
        for(char &i :brokenLetters) present[i - 'a'] = true;
        
        int n = text.size(), ans = 0;
        
        vector<int> spacePositions;
        
        spacePositions.push_back(-1);
        for(int i = 0; i < n; i++) {
            if(text[i] == ' ') spacePositions.push_back(i);
        }
        spacePositions.push_back(n);
        
        for(int i = 0; i < spacePositions.size() - 1; i++) {
            bool f = true;
            int left = spacePositions[i] + 1;
            int right = spacePositions[i+1] - 1;
            
            for(int j = left; j <= right; j++) {
                if(present[text[j] - 'a']) {
                    f = false;
                    break;
                }
            }
            
            if(f) ans++;
        }
        
        return ans;
    }
};