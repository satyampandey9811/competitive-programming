// link to question - https://leetcode.com/problems/number-of-days-between-two-dates/

class Solution {
public:
    vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    bool leapyear(int y){
        return (y % 400 == 0) or (y % 4 == 0 and y % 100 != 0);
    }
    
    int cal(int d, int m, int y){
        int ans = 0;
        int day = 0, mon = 1, year = 1971;
        while(year < y){
            ans += leapyear(year) ? 366 : 365;
            year++;
        }
        while(mon < m){
            ans += days[mon - 1];
            mon++;
        }
        ans += d;
        if(leapyear(y) and m > 2) ans++;
        return ans;
    }
    
    int daysBetweenDates(string a, string b) {            
        int y1 = stoi(a.substr(0, 4));
        int y2 = stoi(b.substr(0, 4));
        int m1 = stoi(a.substr(5, 2));
        int m2 = stoi(b.substr(5, 2));
        int d1 = stoi(a.substr(8, 2));
        int d2 = stoi(b.substr(8, 2));
        int ans1 = cal(d1, m1, y1);
        int ans2 = cal(d2, m2, y2);
        return abs(ans1 - ans2);
    }
};