// link to question - https://leetcode.com/problems/design-a-stack-with-increment-operation/

class CustomStack {
    vector<int> a;
    int size;
    int top;
public:
    CustomStack(int maxSize) {
        a.resize(maxSize, 0);
        size = maxSize;
        top = -1;
    }
    
    void push(int x) {
        if(top < size - 1)
            a[++top] = x;        
    }
    
    int pop() {
        if(top == -1)
            return -1;
        int x = a[top];
        top--;
        return x;
    }
    
    void increment(int k, int val) {
        if(top < k - 1){
            for(int i = 0; i <= top; i++)
                a[i] += val;
            return;
        }
        for(int i = 0; i < k; i++)
            a[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */