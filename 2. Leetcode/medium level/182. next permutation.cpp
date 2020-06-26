// link to question - https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        bool f = true;
        int n = a.size();
        for(int i = 0; i < n - 1; i++) {
            if(a[i] < a[i+1]) {
                f = false;
                break;
            }
        }
        if(f) {
            sort(a.begin(), a.end());
            return;
        }
        int j = n - 1;
        while(a[j] == a[j-1]) {
            j--;
        }
        if(a[j] > a[j-1]) {
            swap(a[j], a[j-1]);
            return;
        }
        vector<int> v = {a[j]};
        j--;
        while(a[j] <= a[j-1]) {
            v.push_back(a[j]);
            j--;
        }
        v.push_back(a[j--]);
        v.push_back(a[j]);
        sort(v.begin(), v.end());
        int val = *upper_bound(v.begin(), v.end(), a[j]);
        for(int i = j + 1; i < n; i++) {
            if(a[i] == val) {
                swap(a[i], a[j]);
                break;
            }
        }
        sort(a.begin() + j + 1, a.end());           
    }
};