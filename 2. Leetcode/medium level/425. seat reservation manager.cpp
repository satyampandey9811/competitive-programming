// link to question - https://leetcode.com/problems/seat-reservation-manager/

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    
    SeatManager(int n) {
        for(int j = 1; j <= n; j++) pq.push(j);
    }
    
    int reserve() {
        int ans = pq.top();
        pq.pop();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
        
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */