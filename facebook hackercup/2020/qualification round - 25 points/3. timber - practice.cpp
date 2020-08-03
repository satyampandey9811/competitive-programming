#include <bits/stdc++.h>
using namespace std;

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
    int n;
    cin >> n;   
    vector<vector<int>> a(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }     
    sort(all(a));
    unordered_map<int, int> m;
    int ans = 0, x, y;

    for(int i = 0; i < n; i++) {
        x = a[i][0], y = a[i][1];
        m[x+y] = max(m[x+y], m[x] + y);
        m[x] = max(m[x], m[x-y] + y);
        ans = max({ans, m[x], m[x+y]});
    }
    cout << ans;
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