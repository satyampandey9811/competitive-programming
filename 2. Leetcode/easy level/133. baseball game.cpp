// link to question - https://leetcode.com/problems/baseball-game/

class Solution {
public:
    int calPoints(vector<string>& a) {
        int ans = 0, x, y, z;
        stack<int> s;
        
        for(int i = 0; i < a.size(); i++){
            if(a[i][0] == 'C')
                s.pop();            
            else if(a[i][0] == 'D')
                s.push(s.top() * 2);
            
            else if(a[i][0] == '+'){
                x = s.top();
                s.pop();
                y = s.top();
                z = x + y;
                s.push(x);
                s.push(z);
            }
            else{                
                x = stoi(a[i]);
                s.push(x);                
            }
        }
        
        while(!s.empty()){            
            ans += s.top();
            s.pop();
        }
        
        return ans;
    }
};