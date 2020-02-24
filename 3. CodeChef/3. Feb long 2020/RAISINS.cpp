// link to question - https://www.codechef.com/FEB20B/problems/RAISINS

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define md 1000000007

void testcase(){
    int w, h, r;
    cin >> w >> h >> r;
    vector<pair<int, int>> a(r);
    for(int i = 0; i < r; i++){
        cin >> a[i].first >> a[i].second;
    }
    cout << 1 << ' ' << 1 << ' ' << 0;
}

signed main() {
#ifdef SP
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--){
        testcase();
        cout << '\n';
    }
    return 0;
}