#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define pi 3.1415926535897932384626
#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << ' : ' << x << endl;
#define deb2(x, y) cout << #x << ' : ' << x << ', ' << #y << ' : ' << y << endl;

template <typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T&... args) {
    ((cout << args << " "), ...);
}

void testcase() {
    int n;
    read(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1) {
        cout << 1;
        return;
    }
    int ans = 1;
    int c = 1;
    int diff = a[1] - a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] - a[i-1] == diff) c++;
        ans = max(ans, c);
        if(a[i] - a[i-1] != diff) {
            c = 2;
            diff = a[i] - a[i-1];
        }
    }
    cout << ans;
}

signed main() {
#ifdef SP
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(NULL);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        testcase();
        cout << endl;
    }
}