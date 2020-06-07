// link to question - leetcode.com/problems/the-k-strongest-values-in-an-array/

class Solution {
public:
    vector<int> getStrongest(vector<int>& a, int k) {
        vector<int> ans;
        int n = a.size();
        sort(a.begin(), a.end());
        int m = a[(n-1)/2];
        int i = 0, j = n - 1;
        int c = 0;
        while(i <= j and c < k) {
            int res;
            if(abs(a[i] - m) > abs(a[j] - m)) {
                res = a[i];
                i++;
            }
            else {
                res = a[j];
                j--;
            }
            ans.push_back(res);
            c++;
        }
        return ans;
    }
};