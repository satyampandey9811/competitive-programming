// link to question - https://leetcode.com/problems/implement-queue-using-stacks/

#include<stack>

class MyQueue {
    stack<int> a;
    int size;
public:
    /** Initialize your data structure here. */
    MyQueue() {        
        size = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {        
        if(a.empty()){
            a.push(x);
            size++;
            return;
        }
        int val = a.top();
        a.pop();
        push(x);
        a.push(val);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = a.top();
        a.pop();
        size--;
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        return a.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */