// link to question - https://leetcode.com/problems/reordered-power-of-2/

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> a;
        while(n) {
            a.push_back(n % 10);
            n /= 10;
        }
        
        sort(a.begin(), a.end());
        
        do {
            if(a[0] == 0) continue;
            
            long long v = 0;
            for(int i = 0; i < a.size(); i++) {
                v *= 10;
                v += a[i];
            }
            
            if((v & (v - 1)) == 0) return 1; 
            
        } while(next_permutation(a.begin(), a.end()));
        
        return 0;
    }
};