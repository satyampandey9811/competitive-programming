// link to question - https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

bool comp(string& a, string& b) {
    if(a.size() > b.size()) return 1;
    return 0;
}

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int n = d.size(), m = s.size();
        sort(d.begin(), d.end(), comp);
        
        string ans;
        int len = 0, j, k;
        
        for(int i = 0; i < n; i++) {            
            j = 0, k = 0;
            
            if(len > d[i].size()) break;
            
            while(j < d[i].size() and k < m) {
                if(d[i][j] == s[k]) j++;
                k++;
            }
            
            if(j == d[i].size()) {
                if(j > len) {
                    len = j;
                    ans = d[i];
                }
                else if(j == len) {
                    j = 0;
                    while(j < len) {
                        if(d[i][j] < ans[j]) {
                            ans = d[i];
                            break;
                        }
                        else if(d[i][j] > ans[j]) {
                            break;
                        }
                        j++;
                    }
                }
            }
        }
        
        return ans;
    }
};