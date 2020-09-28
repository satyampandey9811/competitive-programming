// link to question - https://leetcode.com/problems/subarray-product-less-than-k/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        if(k < 2) return 0;
        
        int ans = 0, n = a.size();
        int i = 0, j = 0, c = 0;
        long long prod = 1;                
        
        while(i < n) {
            prod *= a[i];
            if(prod < k) {
                c++;
                i++;
            }
            else {
                prod /= a[j];
                prod /= a[i];
                j++;                
                cout << c << endl;
                ans += c * (c + 1) / 2;
                c--;
            }
        }
        
        if(prod < k) {
            cout << c << endl;
            ans += c * (c + 1) / 2;
        }

        return ans;
    }
};