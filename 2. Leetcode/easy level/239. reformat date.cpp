// link to question - https://leetcode.com/problems/reformat-date/

class Solution {
public:
    string reformatDate(string a) {        
        map<string, string> m = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};        
        string date;
        if(a[1] > '9') date = a[0];
        else date = a.substr(0,2);
        string month = m[a.substr(n-8, 3)];
        string year = a.substr(n-4);
        
        string ans = year + '-' + month + '-';
        if(date.size() == 1) date = '0' + date;
        ans += date;
        return ans;
    }
};