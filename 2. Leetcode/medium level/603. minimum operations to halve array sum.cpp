// link to question - https://leetcode.com/problems/minimum-operations-to-halve-array-sum/

class Solution {
public:
    int halveArray(vector<int>& a) {
        int ans = 0;
        double res = 0;
        for (auto &i :a) res += i;
        
        double sum = res;

        priority_queue<double> pq;
        for (auto &i :a) pq.push(i);
        
        double val;
        
        while (sum * 2 > res) {
            val = pq.top();
            pq.pop();
            pq.push(val / 2);
            sum -= val / 2;
            ans++;
        }
        
        return ans;
    }
};