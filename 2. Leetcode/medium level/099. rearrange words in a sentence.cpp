// link to question - https://leetcode.com/problems/rearrange-words-in-a-sentence/

class Solution {
public:
    string arrangeWords(string a) {
        string ans;
        int n = a.size();
        multiset<pair<int, int>> s;
        map<int, string> m;
        
        a[0] = tolower(a[0]);
        string temp;
        for(int i = 0; i < n; i++) {
            if(a[i] == ' ') {
                s.insert({temp.size(), i - temp.size()});
                m[i - temp.size()] = temp;
                temp = "";
            }
            else
                temp += a[i];
        }
        s.insert({temp.size(), n - temp.size()});
        m[n - temp.size()] = temp;
        
        for(auto i: s) {
            ans += m[i.second];
            ans += ' ';
        }
        ans[0] = toupper(ans[0]);
        ans.pop_back();
        return ans;
    }
};