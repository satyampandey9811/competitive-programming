// link to question - https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue {
public:
    int i, j, n;
    vector<int> a;
    
    MyCircularQueue(int k) {
        a.resize(k, -1);
        n = k, i = -1, j = -1;
    }
    
    bool enQueue(int value) {
        if(isFull()) return 0;
        if(i == -1) i = 0;
        j = (j + 1) % n;
        a[j] = value;
        return 1;
    }
    
    bool deQueue() {
        if(isEmpty()) return 0;
        if(i == j) i = -1, j = -1;
        else i = (i + 1) % n;
        return 1;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return a[i];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return a[j];
    }
    
    bool isEmpty() {
        return i == -1;
    }
    
    bool isFull() {
        return (j + 1) % n == i;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */