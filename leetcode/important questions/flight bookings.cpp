// link to question - https://leetcode.com/problems/corporate-flight-bookings/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& a, int n) {
        
        int m=a.size();
        vector<int> b(n);
        int x,y;
        for(int i=0;i<m;i++){
            
            x=a[i][0]-1;
            y=a[i][1]-1;
            b[x]+=a[i][2];
            if(y+1<n)
                b[y+1]-=a[i][2];
        }
        
        for(int i=1;i<n;i++){
            b[i]+=b[i-1];
        }
        
        return b;
    }
};