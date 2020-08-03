// codejam
// 1a round 

// done after the contest

#include<bits/stdc++.h>
using namespace std;

bool comp(pair<string, int> a, pair<string, int> b){
    return a.second < b.second;
}

string helper(vector<pair<string, int>> &a, int n){
    string ans = a[n - 1].first;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0, k = 0; j < a[i].second; j++, k++){
            if(a[i].first[j] != ans[k])
                return "no";
        }
    }
    return ans;
}

void testcase(){
    int n;
    cin >> n;
    vector<string> a;
    string ans;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        a.push_back(s);
    }

    vector<pair<string, int>> pre, post;

    for(int i = 0; i < n; i++){
        string temp;
        for(int j = 0; a[i][j] != '*'; j++){
            temp += a[i][j];
        }
        pre.push_back({temp, (int)temp.size()});
    }

    for(int i = 0; i < n; i++){
        string temp;
        for(int j = a[i].size() - 1; a[i][j] != '*'; j--){
            temp += a[i][j];
        }
        post.push_back({temp, (int)temp.size()});
    }

    sort(pre.begin(), pre.end(), comp);
    sort(post.begin(), post.end(), comp);

    string temp1, temp2;
    temp1 = helper(pre, n);
    if(temp1 == "no"){
        cout << "*";
        return;
    }
    temp2 = helper(post, n);
    if(temp2 == "no"){
        cout << "*";
        return;
    }

    ans += temp1;

    for(int i = 0; i < n; i++){
        int star = 0, pos;
        for(int j = 0; j < a[i].size(); j++){
            if(a[i][j] == '*'){
                star++;
                if(star == 1) pos = j;
            }
        }

        if(star < 2) continue;

        for(int j = pos + 1, c = 1; c < star; j++){
            if(a[i][j] == '*') c++;
            else ans += a[i][j];
        }
    }
    reverse(temp2.begin(), temp2.end());
    ans += temp2;

    cout << ans;
}

int main(){
#ifdef  SP
    freopen("in.txt","r",stdin);
#endif
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ':' << ' ';
        testcase();
        cout << '\n';
    }
}