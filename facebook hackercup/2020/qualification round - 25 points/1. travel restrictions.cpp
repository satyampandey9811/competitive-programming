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
    string in, out;
    cin >> in >> out;
    vector<vector<char>> a(n, vector<char>(n, 'N'));
    for(int i = 0; i < n; i++) {
        a[i][i] = 'Y';
        int l = i, r = i;
        if(out[i] == 'N') continue;
        while(l - 1 >= 0 and out[l] == 'Y' and in[l-1] == 'Y') a[i][l-1] = 'Y', l--;
        while(r + 1 < n and out[r] == 'Y' and in[r+1] == 'Y') a[i][r+1] = 'Y', r++;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
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
        cout << endl;
        testcase();        
    }
}