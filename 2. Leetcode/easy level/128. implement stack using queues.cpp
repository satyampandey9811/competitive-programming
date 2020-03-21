// link to question - https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
    queue<int> a;
    int size;
public:
    /** Initialize your data structure here. */
    MyStack() {
        size = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        a.push(x);
        size++;
        int i = size -1;
        while(i){
            int val = a.front();
            a.pop();
            a.push(val);
            i--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = a.front();
        a.pop();
        size--;
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return a.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */