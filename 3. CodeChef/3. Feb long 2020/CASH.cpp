// link to question - https://www.codechef.com/FEB20B/problems/CASH

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define md 1000000007

void testcase(){
    int n, k, ans = 0;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        ans += a[i] % k;
    }
    cout<<ans % k;
}

signed main() {
#ifdef SP
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        testcase();
        cout << '\n';
    }
    return 0;
}
