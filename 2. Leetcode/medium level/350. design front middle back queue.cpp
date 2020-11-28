// link to question - https://leetcode.com/problems/design-front-middle-back-queue/

class FrontMiddleBackQueue {
public:
    deque<int> d;
    
    FrontMiddleBackQueue() {
        d.clear();    
    }
    
    void pushFront(int val) {
        d.push_front(val);
    }
    
    void pushMiddle(int val) {
        auto it = d.begin();        
        int n = d.size();
        if(n & 1) n = (n - 1) / 2;    
        else n = n / 2;
        for(int i = 0; i < n; i++) it++;
        it = d.insert(it, val);        
    }
    
    void pushBack(int val) {
        d.push_back(val);
    }
    
    int popFront() {
        if(d.size() == 0) return -1;
        int val = d[0];
        d.pop_front();
        return val;
    }
    
    int popMiddle() {
        if(d.size() == 0) return -1;
        int n = d.size();
        n = (n - 1) / 2;
        int val = d[n];
        auto it = d.begin();
        for(int i = 0; i < n; i++) it++;
        d.erase(it);
        return val;
    }
    
    int popBack() {
        if(d.size() == 0) return -1;
        int val = d.back();
        d.pop_back();
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */