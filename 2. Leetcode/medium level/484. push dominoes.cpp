// link to question - https://leetcode.com/problems/push-dominoes/

class Solution {
public:
    string pushDominoes(string a) {
        vector<int> left, right;
        int n = a.size();
        for(int i = 0; i < n; i++) {
            if(a[i] == 'L') left.push_back(i);
            else if(a[i] == 'R') right.push_back(i);
        }
        
        int i = 0, l = 0, r = 0, ls = left.size(), rs = right.size();
        
        while(l < ls and r < rs) {
            if(left[l] < right[r]) {
                while(i <= left[l]) a[i++] = 'L';
                l++;
            }
            else {
                int x = right[r];
                while(r < rs and right[r] < left[l]) r++;
                r--;
                while(x < right[r]) a[x++] = 'R';
                
                int j = right[r] + 1, k = left[l] - 1;
                while(j < k) {
                    a[j++] = 'R';
                    a[k--] = 'L';
                }
                i = left[l] + 1;
                l++, r++;
            }
        }
        if(r < rs) {
            i = right[r] + 1;
            while(i < n) a[i++] = 'R';
        }
        if(l < ls) {
            i = left.back() - 1;
            while(i >= 0) a[i--] = 'L';
        }
        
        return a;
    }
};