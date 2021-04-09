// link to question - https://leetcode.com/problems/verifying-an-alien-dictionary/

class Solution {
public:
    bool isAlienSorted(vector<string>& w, string order) {
        vector<int> a(26);
        for(int i = 0; i < order.size(); i++) {
            a[order[i] - 'a'] = i;
        }
        
        for(int i = 0; i < w.size() - 1; i++) {
            int j = 0;
            while(j < w[i].size() and j < w[i+1].size()) {
                if(a[w[i][j] - 'a'] == a[w[i+1][j] - 'a']) j++;
                else if(a[w[i][j] - 'a'] < a[w[i+1][j] - 'a']) break;
                else return 0;
            }
            if(w[i+1].size() < w[i].size() and j == w[i+1].size()) return 0;
        }
        
        return 1;
    }
};