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
	if (cu != 0 and cu <= cb) {
		cout << "Y";
	}
	else
		cout << "N";
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