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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n ; i++){
        cin >> a[i];
    }
    int ans = 0;
    if(n == 1) ans++;
    else if(n > 1 and a[0] > a[1]) ans++;
    int max = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] > max) {
            max = a[i];
            if(i == n - 1) ans++;
            else if(a[i] > a[i+1]) ans++;
        }
    }
    cout << ans;
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