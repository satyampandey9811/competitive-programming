// link to question - https://leetcode.com/problems/maximum-profit-of-operating-a-centennial-wheel/

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int cost = -1, ans = 0;
        int n = customers.size(), wait = 0;
        int currcost, rot = 0, passenger = 0;
        
        for(int i = 0; i < n; i++) {
            rot++;
            wait += customers[i];
            passenger += min(4, wait);
            currcost = passenger * boardingCost - rot * runningCost;
            wait -= min(4, wait);
            
            if(currcost > cost) {
                cost = currcost;
                ans = rot;
            }
        }
        
        while(wait) {
            rot++;
            passenger += min(4, wait);
            currcost = passenger * boardingCost - rot * runningCost;
            wait -= min(4, wait);
            
            if(currcost > cost) {
                cost = currcost;
                ans = rot;
            }
        }
        
        return cost == -1 ? -1 : ans;
    }
};