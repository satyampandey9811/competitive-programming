// link to question - https://leetcode.com/problems/custom-sort-string/

class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> a(26);
        for(char &c :str) a[c - 'a']++;
        
        string ans;
        int n = order.size();
        
        for(char &c : order) {
            for(int j = 0; j < a[c - 'a']; j++) ans += c;
            a[c - 'a'] = 0;
        }
        
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < a[i]; j++) ans += (char)97 + i;
        }
        
        return ans;
    }
};