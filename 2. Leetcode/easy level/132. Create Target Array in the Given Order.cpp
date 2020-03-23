// link to question - Create Target Array in the Given Order

class Solution {
public:
    vector<int> createTargetArray(vector<int>& num, vector<int>& ind) {
        int n = ind.size();
        vector<int> ans(n, -1);
        
        for(int i = 0; i < n; i++){
            int x = num[i];
            int y = ind[i];
            if(ans[y] == -1)
                ans[y] = x;
            else{
                for(int j = n - 1; j > y; j--)
                    ans[j] = ans[j - 1];
                ans[y] = x; 
            }
        }
        
        return ans;
    }
};