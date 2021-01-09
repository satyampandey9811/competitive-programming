// link to question - https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string s, string e, vector<string>& wordList) {
        unordered_set<string> w(wordList.begin(), wordList.end());        
        queue<string> q;
        q.push(s);
        int ans = 1;
        
        while(q.size()) {
            for(int i = q.size(); i > 0; i--) {
                auto front = q.front();
                if(front == e) return ans;
                q.pop();
                w.erase(front);
                for(int j = 0; j < front.size(); j++) {
                    char c = front[j];
                    for(char k = 'a'; k <= 'z'; k++) {                        
                        front[j] = k;
                        if(w.count(front)) {
                            q.push(front);
                            w.erase(front);
                        }
                    }                    
                    front[j] = c;
                }
            }
            ans++;
        }
        
        return 0;
    }
};