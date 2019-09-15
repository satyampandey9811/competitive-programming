// link to question - https://leetcode.com/problems/di-string-match/

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size(),b = 0;
        int c = n;
        vector<int> output;
        for(int i = 0; i < n; i++){
            if(s[i] == 'I')
                output.push_back(b++);
            
            else output.push_back(c--);
        }
        output.push_back(c);
        return output;
    }
};