// link to question - https://leetcode.com/problems/min-stack/

class node{
public:
    int val, minval;
    node *next;    
    node(int x){
        val = x;        
        minval = x;
    }
};

class MinStack {
public:
    /** initialize your data structure here. */
    node *head;
    
    MinStack() {
        head = NULL;
    }
    
    void push(int x) {
        node *temp = new node(x);
        if(head){
            temp -> minval = min(temp -> minval, head -> minval);
        }
        temp -> next = head;
        head = temp;
    }
    
    void pop() {
        node *temp = head;
        head = head -> next;
        delete temp;
    }
    
    int top() {
        return head -> val;
    }
    
    int getMin() {
        return head -> minval;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */