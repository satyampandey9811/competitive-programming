// link to question - https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

class Solution {
public:
    int smallestChair(vector<vector<int>>& t, int far) {
        int n = t.size();
        int lmx = 0;
        
        set<pair<int, int>> a, l;
        
        for(int i = 0; i < n; i++) {
            a.insert({t[i][0], i});
            l.insert({t[i][1], i});
            
            lmx = max(lmx, t[i][1]);
        }
        
        set<int> d;
        
        for(int i = 0; i < n; i++) d.insert(i);
        
        map<int, int> m;
        
        for(int i = 1; i <= lmx; i++) {
            auto it = l.lower_bound({i, 0});
            
            while(it != l.end()) {
                if((*it).first != i) break;
                int p = it -> second;
                d.insert(m[p]);
                l.erase(it);
                it = l.lower_bound({i, 0});
            }
            
            it = a.lower_bound({i, 0});
            
            int arr = (*it).first, per = (*it).second;
            
            if(arr == i) {
                m[per] = *d.begin();
                d.erase(d.begin());
                if(per == far) 
                    return m[per];
            }
        }
        
        return 0;
    }
};