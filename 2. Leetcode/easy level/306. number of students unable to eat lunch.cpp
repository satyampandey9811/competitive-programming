// link to question - https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

class Solution {
public:
    int countStudents(vector<int>& a, vector<int>& b) {
        int n = a.size();
        
        int ans = 0;
        deque<int> s;
        for(int i = 0; i < n; i++) {
            s.push_back(a[i]);
        }
        
        int j = 0;
        int c = 0;
        while(1) {
            if(s.front() == b[j]) {
                ans++;
                j++;                
                s.pop_front();
                c = 0;
            }
            else {
                auto k = s.front();
                s.pop_front();
                s.push_back(k);
                c++;
            }
            if(c == s.size()) break;
            if(j == n) break;                    
        }
        
        return n - ans;
    }
};