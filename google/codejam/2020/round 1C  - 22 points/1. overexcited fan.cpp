#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
//#define int long long
#define mod 1000000007
#define endl '\n'
#define deb(x) cout << #x << ' ' << x << endl;

void testcase(){
    int px, py, c = 0, sx = 0, sy = 0, a, b;
    string s;
    cin >> px >> py >> s;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'N') py++;
        else if(s[i] == 'S') py--;
        else if(s[i] == 'E') px++;
        else px--;
        c++;
        a = abs(py - sy);
        b = abs(px - sx);
        if(px == sx and py == sy) {
            cout << c;
            return;
        }
        if(py > sy and px > sx){
            if(a > b) sy++;
            else if(b > a) sx++;
        }
        else if(py > sy and px < sx){
            if(a > b) sy++;
            else if(b > a) sx--;
        }
        else if(py < sy and px > sx){
            if(a > b) sy--;
            else if(b > a) sx++;
        }
        else if(py < sy and px < sx){
            if(a > b) sy--;
            else if(b > a) sx--;
        }
        else if(px == sx){
            if(py > sy) sy++;
            else if(sy > py) sy--;
        }
        else if(py == sy){
            if(px > sx) sx++;
            else if(sx > px) sx--;
        }
        if(px == sx and py == sy) {
            cout << c;
            return;
        }
    }
    cout << "IMPOSSIBLE";
}

signed main() {
#ifdef SP
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        testcase();
        cout << endl;
    }
    return 0;
}