// link to question - https://leetcode.com/problems/unique-morse-code-words/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> r = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."} ;
        
        unordered_set<string> s;
        for(int i = 0; i < words.size(); i++) {
            string t;
            for(int j = 0; j < words[i].size(); j++) {
                t += r[words[i][j] - 'a'];
            }
            s.insert(t);
        }
        
        return s.size();
    }    
};