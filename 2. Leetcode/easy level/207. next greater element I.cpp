// link to question - https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> ans(n, -1);
        
        unordered_map<int, int> m;
        for(int i = 0; i < b.size(); i++) {
            m[b[i]] = i;
        }
        
        for(int i = 0; i < n; i++) {
            int j = m[a[i]] + 1;
            while(j < b.size()) {
                if(b[j] > a[i]) {
                    ans[i] = b[j];
                    break;
                }
                j++;
            }
        }
        
        return ans;
    }
};