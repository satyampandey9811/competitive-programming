#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define pi 3.1415926535897932384626
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << ' : ' << x << endl;
#define deb2(x, y) cout << #x << ' : ' << x << ', ' << #y << ' : ' << y << endl;
#define Yes cout << "Yes";
#define YES cout << "YES";
#define No cout << "No";
#define NO cout << "NO";

void testcase(){
    int n, m;
    cin >> n >> m;
    vector<int> c(1000009), dp(1000009);
    for(int i = 0; i < n; i++) cin >> c[i];
    int i = 0, j = 0;
    set<pair<int, int>> s;
    while(i <= m and i < n) {
        dp[i] = 0;
        if(c[i]) s.insert({c[i], i});
        i++;
    }

    while(i < n) {
        if(c[j]) s.erase({c[j] + dp[j], j});
        if(s.size() == 0) {
            cout << -1;
            return;
        }
        auto it = s.begin();
        dp[i] = (*it).first;
        if(c[i]) s.insert({c[i] + dp[i], i});
        i++, j++;
    }
    if(i == n) cout << dp[n-1];
}

signed main() {
#ifdef SP
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(NULL);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";        
        testcase();        
        cout << endl;
    }
}