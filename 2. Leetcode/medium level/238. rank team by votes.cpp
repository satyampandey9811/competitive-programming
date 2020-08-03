// link to question - https://leetcode.com/problems/rank-teams-by-votes/

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        
        vector<vector<int>> count(26, vector<int>(27));
        for (char& c: votes[0])
            count[c - 'A'][26] = c;

        for (string& vote: votes)
            for (int i = 0; i < vote.length(); ++i)
                count[vote[i] - 'A'][i]--;
        
        // for(int i = 0; i < 26; i++) {
        //     for(int j = 0; j <= 26; j++) cout << count[i][j] << ' ';
        //     cout << endl;
        // }
        // cout << endl;
        
        sort(count.begin(), count.end());
        
        // for(int i = 0; i < 26; i++) {
        //     for(int j = 0; j <= 26; j++) cout << count[i][j] << ' ';
        //     cout << endl;
        // }
        
        string res;
        for (int i = 0; i < votes[0].length(); ++i)
            res += count[i][26];
        
        return res;
    }
};