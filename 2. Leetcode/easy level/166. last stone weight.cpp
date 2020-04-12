// link to question - https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& a) {          
        int x, y;
        
        while(a.size() > 1){
            sort(a.begin(), a.end());
            x = a[a.size() - 2];
            y = a[a.size() - 1];
            a.pop_back(); a.pop_back();
            if(x != y) 
                a.push_back(y - x);            
        }
        
        return a.size() ?a[0] :0;
    }
};