// link to question - https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    // important question
    // not my approach
    /** initialize your data structure here. */
    priority_queue<int> p;
    priority_queue<int, vector<int>, greater<int>> q;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        p.push(num);
        q.push(p.top());
        p.pop();
        if (p.size() < q.size()) {
            p.push(q.top());
            q.pop();
        }
    }

    double findMedian() {
        return p.size() > q.size()
               ? p.top()
               : (p.top() + q.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */