// link to question - https://leetcode.com/problems/uncommon-words-from-two-sentences/

class Solution {
public:
    unordered_map<string, int> m;
    void cal(string a, int n){
        string w = "";
        for(int i = 0; i < n; i++){        
            if(a[i] == ' '){
                m[w]++;
                w = "";
                continue;
            }
            w += a[i];
        }
        m[w]++;
    }
    vector<string> uncommonFromSentences(string a, string b) {
        vector<string> ans;
        cal(a,a.size());
        cal(b,b.size());
        for(auto x: m){
            if(x.second == 1) 
                ans.push_back(x.first);
        }
        return ans;
    }
};