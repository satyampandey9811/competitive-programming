// link to question - https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

class Solution {
public:
    double average(vector<int>& a) {
        sort(a.begin(), a.end());
        double sum = 0.0;        
        int n = a.size();
        
        for(int i = 1; i < n - 1; i++) {
            sum += a[i];                        
        }
                
        sum /= n - 2;
        return sum;
    }
};