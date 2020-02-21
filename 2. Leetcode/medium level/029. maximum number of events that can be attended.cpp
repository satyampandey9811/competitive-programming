// link to question - https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

struct event{
  int first, second;  
};

bool comp(event a, event b){
    if(a.second == b.second)
        return a.first <= b.first;
    return a.second < b.second;
}

class Solution {
public:
    int maxEvents(vector<vector<int>>& a) {
        int n = a.size();
        vector<event> b(n);
        unordered_set<int> res;
        for(int i = 0; i < n; i++){
            b[i].first = a[i][0];
            b[i].second = a[i][1];
        }
        sort(b.begin(), b.end(), comp);
        for(int i = 0; i < n; i++){
            for(int j = b[i].first; j <= b[i].second; j++){
                if(res.find(j) == res.end()){
                    res.insert(j);
                    break;
                }
            }            
        }        
        return res.size();
    }
};