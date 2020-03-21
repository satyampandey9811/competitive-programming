// link to question - https://leetcode.com/problems/sort-integers-by-the-power-value/

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        
        vector<pair<int, int>> a;        
        
        for(int i = lo; i <= hi; i++){
            int c = 0, x = i;
            
            while(x != 1){
                c++;
                if(x & 1)
                    x = (3 * x) + 1;
                else
                    x /= 2;                
            }            
            a.push_back({c, i});            
        }
        
        sort(a.begin(), a.end());
        return a[k - 1].second;
    }
};