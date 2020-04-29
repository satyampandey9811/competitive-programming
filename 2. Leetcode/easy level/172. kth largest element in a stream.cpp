// link to question - https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
    
public:
    KthLargest(int k, vector<int>& a) {
        for(int i = 0; i < a.size() and i < k; i++){
            pq.push(a[i]);
        }
        for(int i = k; i < a.size(); i++){
            if(a[i] > pq.top()){
                pq.pop();
                pq.push(a[i]);
            }
        }
        size = k;
    }
    
    int add(int val) {
        // if(pq.size() == size and val > pq.top()){
        //     pq.pop();
        //     pq.push(val);
        // }
        // else if(pq.size() < size)
        //     pq.push(val);
        pq.push(val);
        if(pq.size() > size)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */