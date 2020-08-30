// link to question - https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/

class Solution {
public:
    int cal(vector<int>& a, int low, int high){
        int negcount = 0, i, j, k; 
        
        for(i = low; i <= high; i++) {            
            if(a[i] < 0) negcount++;
        }
        if(negcount % 2 == 0) return high - low + 1; 
        
        for(i = low; a[i] > 0; i++);
        for(j = high; a[j] > 0; j--);                
        
        return max(j - low, high - i);
    }
    
    int getMaxLen(vector<int>& a) {
        int ans = 0, val = 0;
        vector<int> zeropos = {-1};    
        
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == 0) zeropos.push_back(i);                        
        }
        zeropos.push_back(a.size());
        
        for(int i = 0; i < zeropos.size() - 1; i++) {
            if(zeropos[i+1] == zeropos[i] + 1) continue;
            else if(zeropos[i+1] == zeropos[i] + 2) {
                if(a[zeropos[i] + 1] > 0) ans = max(ans, 1);
            }
            else val = cal(a, zeropos[i] + 1, zeropos[i+1] - 1);
            ans = max(ans, val);
        }
                     
        return ans;
    }
};