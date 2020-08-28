// link to question - https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n, mid;
        
        while(low < high) {
            mid = low + (high - low) / 2;
            int c = 0, size = min(m, mid);                        
            
            for(int i = 1; i <= size; i++) {
                c += min(n, mid / i);
                cout << c << ' ';
            }
            cout << endl;
            cout << low << ' ' << mid << ' ' << high << ' ' << c << endl;
            
            if(c < k) low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
};