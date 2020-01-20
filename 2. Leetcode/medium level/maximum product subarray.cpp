// link to question - https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int cal(vector<int>& a, int low, int high){
        int negcount = 0, prod = 1, i, j, k, left_prod = 1, right_prod = 1;  
        
        for(i = low; i <= high; i++){
            prod *= a[i];
            if(a[i] < 0)
                negcount++;
        }
        if(negcount % 2 == 0)
            return prod; 
        
        for(i = low; a[i] > 0; i++);
        for(j = high; a[j] > 0; j--);
        
        for(k = low; k < j; k++) left_prod *= a[k];
        for(k = high; k > i; k--) right_prod *= a[k];
        
        return max(left_prod, right_prod);
    }
    
    int maxProduct(vector<int>& a) {
        int ans = INT_MIN, val;
        vector<int> zeropos = {-1};
        
        for(int i = 0; i < a.size(); i++){
            if(a[i] == 0){
                ans = 0;
                zeropos.push_back(i);            
            }
        }
        zeropos.push_back(a.size());
        
        for(int i = 0; i < zeropos.size() - 1; i++){
            if(zeropos[i+1] == zeropos[i] + 1) 
                continue;
            else if(zeropos[i+1] == zeropos[i] + 2) 
                val = a[zeropos[i] + 1];
            else
                val = cal(a, zeropos[i] + 1, zeropos[i+1] - 1);
            ans = max(ans, val);
        }
        return ans;
    }
};