// link to question - https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/

class Solution {
public:
    int search(vector<int>& p, int end, int val) {
        int s = 0, mid;
        while(s <= end) {
            mid = s + (end - s) / 2;
            if(p[mid] == val)
                return mid;
            if(p[mid] < val)
                s = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }
    
    int minSumOfLengths(vector<int>& a, int t) {                
        int w, x, y, z;
        w = x = y = z = -1;
        
        vector<int> p = {0};
        for(auto i: a) p.push_back(p.back() + i);
        
        for(int i = 1; i < p.size(); i++) {
            int ans = search(p, i, p[i] - t);
            if(ans != -1) {
                if(x == -1) {
                    w = ans;
                    x = i;
                }
                else if(ans < x) {
                    if(x - w > i - ans) {
                        w = ans;
                        x = i;
                    }
                }
                else if(w != -1 and y == -1){
                    y = ans;
                    z = i;
                }
                else if(ans < z) {
                    if(z - y > i - ans) {
                        y = ans;
                        z = i;
                    }
                }                
                else {
                    if(i - ans < z - y or i - ans < x - w) {
                        if(z - y > x - w) {
                            y = ans;
                            z = i;
                        }
                        else {
                            w = ans;
                            x = i;
                        }
                    }
                }
            }
        }
        
        if(w == -1 or x == -1 or y == -1 or z == -1) return -1;
        return z - y + x - w;
    }
};