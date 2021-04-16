// link to question - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution {
public:
    string removeDuplicates(string a, int k) {
        string ans;
        stack<pair<char, int>> s;
        int n = a.size();
        
        for(int i = 0; i < n; i++) {
            if(!s.size() or s.top().first != a[i]) {
                s.push({a[i], 1});
            }
            else if(s.top().second + 1 < k) {
                s.top().second++;
            }
            else {
                s.pop();
            }
        }
        
        while(s.size()) {
            for(int i = 0; i < s.top().second; i++) {
                ans += s.top().first;
            }
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};