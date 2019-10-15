// link to question - https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<long long int> climbingLeaderboard(vector<long long int> s, vector<long long int> a) {
    vector<long long int> f;
    long long int n=s.size(),m=a.size();
    for(long long int i=0,j=1;i<n;){
        if(s[i]!=s[j]){
            i++;j++;
        }
        else{        
            long long int x=i,y=j;
            while(x<n-1){
                s[x]=s[y];
                x++;y++;
            }
            s[n-1]=0;
            n--;
        }
    }
    for(long long int i=0;i<m;i++){
        long long int p=a[i],j=0,k=n-1;
        while(j<=k){
            long long mid=(j+k)/2;
            if(p==s[mid]){
              f.push_back(mid + 1);
              break;
            } 
            
            else if(p<s[mid]){
              j=mid+1;
            } 
            else if (p >s[mid]) {
              k=mid-1;
            } else if (j == k)
              f.push_back(j + 2);
        }
        if (k == -1)
          f.push_back(1);
        else if(j>k and j<n)
          f.push_back(j+1);
        if(j==n)
          f.push_back(n+1);
        
    }
    return f;
}

int main()
{
    long long int scores_count;
    cin >> scores_count;

    vector<long long int> scores(scores_count);

    for (long long int i = 0; i < scores_count; i++) {        
        cin>>scores[i];
    }

    long long int alice_count;
    cin >> alice_count;

    vector<long long int> alice(alice_count);

    for (long long int i = 0; i < alice_count; i++) {
        cin>>alice[i];
    }

    vector<long long int> result = climbingLeaderboard(scores, alice);

    for (long long int i = 0; i < result.size(); i++) {
        cout << result[i]<<endl;
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
