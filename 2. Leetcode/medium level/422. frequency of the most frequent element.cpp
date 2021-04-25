// link to question - https://leetcode.com/problems/frequency-of-the-most-frequent-element/

class Solution {
public:
    int maxFrequency(vector<int>& a, int k) {
        int n = a.size(), ans = 1;
        sort(a.begin(), a.end());
        
        long long int sum = 0, j = n - 2;
        int c = 1;
        
        for(int i = n - 1; i > 0; i--) {
            while(j >= 0 and sum + a[i] - a[j] <= k) {
                sum += a[i] - a[j];
                c++;
                j--;
            }
            ans = max(ans, c);
            c--;
            sum -= 1LL * a[i] * c;
            sum += 1LL * a[i-1] * c;
        }
        
        return ans;
    }
};