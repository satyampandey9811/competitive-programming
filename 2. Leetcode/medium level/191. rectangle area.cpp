// link to question - https://leetcode.com/problems/rectangle-area/

class Solution {
public:                                        
    int computeArea(int m, int n, int o, int p, int q, int r, int s, int t){
        
        long long int a = m, b = n, c = o, d = p, e = q, f = r, g = s, h = t;
        int width = max(min(c, g) - max(a, e), 0LL);
        int height = max(min(d, h) - max(b, f), 0LL);         
        
        return (c - a) * (d - b) + (g - e) * (h - f) - width * height;
    }
};