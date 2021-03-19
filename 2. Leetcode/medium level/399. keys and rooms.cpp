// link to question - https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& a) {
        queue<int> q;
        q.push(0);
        int n = a.size();
        unordered_set<int> s;
        s.insert(0);
        
        while(q.size()) {
            for(int i = q.size(); i > 0; i--) {
                int f = q.front();
                q.pop();
                
                for(int j = 0; j < a[f].size(); j++) {
                    if(!s.count(a[f][j])) {
                        q.push(a[f][j]);
                        s.insert(a[f][j]);
                        if(s.size() == a.size()) return 1;
                    }
                }
            }
        }
        
        return s.size() == a.size();
    }
};