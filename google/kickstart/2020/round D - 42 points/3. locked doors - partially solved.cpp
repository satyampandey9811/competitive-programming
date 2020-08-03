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
    int n, q;
    cin >> n >> q;                
    vector<vector<int>> a(2, vector<int>(n + 2, INT_MAX));
    for(int i = 1; i < n; i++) {
        cin >> a[1][i];
        a[0][i+1] = a[1][i];        
    } 

    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if(x == 1) {
            cout << y << ' ';
            continue;
        }
        if(x == n) {
            cout << n - y + 1 << ' ';
            continue;
        }
        int l = x - 1, r = x + 1;
        int lwall = a[0][x], rwall = a[1][x];
        int c = 1, ans = x;
        while(c < y) {
            c++;
            if(lwall < rwall) {
                lwall = a[0][l];
                ans = l;
                l--;
            }
            else {
                rwall = a[1][r];
                ans = r;
                r++;
            }
        }
        cout << ans << ' ';
    }
}

signed main() {
#ifdef SP
    freopen("in.txt", "r", stdin);
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