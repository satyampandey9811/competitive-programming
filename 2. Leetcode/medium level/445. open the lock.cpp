// link to question - https://leetcode.com/problems/open-the-lock/

class Solution {
public:
    int openLock(vector<string>& d, string t) {
        unordered_set<string> s(d.begin(), d.end()), vis;
        if(s.count("0000")) return -1;
        int ans = 0;
        queue<string> q;
        q.push("0000");
        vis.insert("0000");
        
        while(q.size()) {
            for(int j = q.size(); j > 0; j--) {
                auto f = q.front();
                q.pop();
                if(f == t) return ans;
                
                string x = f, y = f;
                for(int i = 0; i < 4; i++) {
                    x[i] = char((x[i] - '0' + 1) % 10 + 48);
                    y[i] = char((y[i] - '0' + 9) % 10 + 48);
                    if(!vis.count(x) and !s.count(x)) {
                        vis.insert(x);
                        q.push(x);
                    }
                    if(!vis.count(y) and !s.count(y)) {
                        vis.insert(y);
                        q.push(y);
                    }
                    x[i] = char((x[i] - '0' + 9) % 10 + 48);
                    y[i] = char((y[i] - '0' + 1) % 10 + 48);
                }
            }
            ans++;
        }
        
        return -1;
    }
};