// link to question - https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    int smallestDivisor(vector<int>& a, int t) {
        int low = 1, high = *max_element(a.begin(), a.end()), mid;
        
        while(low < high) {
            mid = low + (high - low) / 2;
            int sum = 0;
            for(int i = 0; i < (int)a.size(); i++) {
                sum += (a[i] + mid - 1) / mid;
            }
            
            if(sum > t) low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
};