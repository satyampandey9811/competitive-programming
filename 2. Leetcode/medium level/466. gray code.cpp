// link to question - https://leetcode.com/problems/gray-code/

class Solution {
public:
    // important question
    vector<int> grayCode(int n) {
        int size = 1 << n;
        
        vector<int> ans(size);
        ans[0] = 0;
        
        vector<bool> present(size);
        present[0] = 1;
        
        for(int i = 1; i < size; i++) {
            int last = ans[i-1];
            
            for(int j = 0; j < n; j++) {
                int current = last ^ (1 << j);
                
                if(current < size and !present[current]) {
                    ans[i] = current;
                    present[current] = 1;
                    break;
                }
            }
        }
        
        return ans;
    }
};