#include <bits/stdc++.h>

using namespace std;

void testcase() {
	string s;
	cin >> s;
	int n = s.size();
	if (n < 3) {
		cout << "N";
		return;
	}
	int cu = 0, cb = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == 'B')cb++;
		else cu++;
	}
	if (cu == 0 or cb==0) {
		cout << "N";
		return;
	}
	if (cu <= cb) {
		cout << "Y";
		return;
	}
	if (cb == 1)
		cout << "N";
	else
		cout << "Y";
}

void main() {
#ifdef SP
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		testcase();
		cout << '\n';
	}

}