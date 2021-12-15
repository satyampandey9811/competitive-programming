// link to question - https://leetcode.com/problems/sequentially-ordinal-rank-tracker/

class SORTracker {
public:
    set<pair<int, string>> s;
    set<pair<int, string>>::iterator it;
    
    SORTracker() {
        it = s.end();
    }
    
    void add(string name, int score) {
        s.insert({score * (-1), name});
        if (it == s.end() or ((-1) * score < (*it).first)) {
            it = prev(it);
        }
        else if ((-1) * score == (*it).first) {
            if (name < (*it).second) it = prev(it);
        }
    }
    
    string get() {
        string ans = it -> second;
        it++;
        return ans;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */