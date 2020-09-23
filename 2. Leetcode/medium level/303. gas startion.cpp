// link to question - https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0, gasSum = 0, costSum = 0, total = 0;
        
        for(int i = 0; i < n; i++) {
            gasSum += gas[i];
            costSum += cost[i];
            total += gas[i] - cost[i];
            if(total < 0) {
                start = i + 1;
                total = 0;
            }
        }
        
        return gasSum < costSum ? -1 : start;
    }
};