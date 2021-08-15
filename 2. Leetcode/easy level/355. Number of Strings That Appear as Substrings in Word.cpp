// link to question - https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

class Solution {
public:
    int numOfStrings(vector<string>& a, string b) {
        int ans = 0, n = a.size();
        
        for(int i = 0; i < n; i++) {
            auto it = b.find(a[i]);
            if(it != string::npos) ans++;
        }
        
        return ans;
    }
};