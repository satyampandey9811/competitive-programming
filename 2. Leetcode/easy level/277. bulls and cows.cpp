// link to question - https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = guess.size();
        int bull = 0, cow = 0;
        vector<int> c(10);
        
        for(int i = 0; i < n; i++) {
            if(secret[i] != guess[i]) c[secret[i] - '0']++;
        }
        
        for(int i = 0; i < n; i++) {
            if(secret[i] == guess[i]) bull++;
            else {
                int x = guess[i] - '0';
                if(c[x]) cow++, c[x]--;                
            }
        }
        
        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};