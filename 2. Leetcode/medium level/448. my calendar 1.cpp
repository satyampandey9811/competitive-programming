// link to question - https://leetcode.com/problems/my-calendar-i/

class MyCalendar {
public:
    set<pair<int, int>> s;
    
    MyCalendar() {
        s.clear();
    }
    
    bool book(int start, int end) {
        start *= 2;
        end *= 2;
        end--;
        auto it = s.lower_bound({start, -10});
        if(it == s.end()) {
            s.insert({start, 1});
            s.insert({end, -1});
            return 1;
        }
        int x = (*it).first, y = (*it).second;
        if(x == start) return 0;
        if(y == -1) return 0;
        
        it = s.lower_bound({end, -10});
        if(it == s.end()) return 0;
        x = (*it).first, y = (*it).second;
        if(x == end) return 0;
        if(y == -1) return 0;
        if(it != s.begin()) {
            it--;
            if((*it).first > start) return 0;
        }
        
        s.insert({start, 1});
        s.insert({end, -1});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */