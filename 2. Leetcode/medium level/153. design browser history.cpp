// link to question - leetcode.com/problems/design-browser-history/

class BrowserHistory {
public:
    vector<string> s;
    int c = 0;
    
    BrowserHistory(string homepage) {
        s.push_back(homepage);    
    }
    
    void visit(string url) {
        while(s.size() > c + 1) {
            s.pop_back();
        }
        s.push_back(url);
        c++;
    }
    
    string back(int steps) {
        if(c - steps >= 0) {
            int x = c - steps;
            c = x;
            return s[x];            
        }
        c = 0;
        return s[0];
    }
    
    string forward(int steps) {
        if(c + steps < s.size()) {
            int x = c + steps;
            c = x;
            return s[x];
        }
        c = s.size() - 1;
        return s.back();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */