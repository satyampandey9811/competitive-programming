// link to question - https://leetcode.com/problems/day-of-the-year/

class Solution {
public:
    int dayOfYear(string date) {
        vector<int> days={31,28,31,30,31,30,31,31,30,31,30,31};
        int ans = (date[8] - '0') * 10 + (date[9] - '0');
        int year = stoi(date.substr(0, 4));
        int month = (date[5] - '0') * 10 + (date[6] - '0');
        bool flag = false;
        if(year % 400 == 0) flag = true; 
        else if(year % 100 == 0) flag = false;
        else if(year % 4 == 0) flag = true;
        
        for(int i = 0; i < month - 1; i++){
            ans += days[i];
            if(i == 1 and flag == true)
                ans += 1;
        }
        return ans;
    }
};