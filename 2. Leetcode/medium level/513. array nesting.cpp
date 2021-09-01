// link to question - https://leetcode.com/problems/array-nesting/

class Solution {
public:
    int arrayNesting(vector<int>& a) {
        int ans = 0, n = a.size(), size, j, temp;
        for(int i = 0; i < n; i++) {
            size = 0, j = i;
            while(a[j] >= 0) {
                size++;
                temp = a[j];
                a[j] = -1;
                j = temp;
            }
            ans = max(ans, size);
        }
        return ans;
    }
};