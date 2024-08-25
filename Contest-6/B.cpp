#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <cmath>
#include <climits>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
#include <array>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
#define ll long long
typedef array<int, 3> triple;
const ll mod = (ll)1e9 + 7;
#define int long long
const int inf = 1000000000;
//const ll inf = (ll)1e18;
const int N = 2e5 + 1;
const int M = 20;

int f[N];

void init() {
	f[0] = 3;
	f[1] = 3 + (1 + 1 + 2) + 3;
	for (int i = 2; i < N; i++) {
		f[i] = f[i - 1] + (1 + i + 2) + f[i - 1];
		if (f[i] > 1e9) break;
	}

}

signed main() {
	init();
	int n;
	cin >> n;

	int p = 0;
	for (int i = 0; i < N; i++) {
		if (f[i] >= n) {
			p = i;
			break;
		}
	}
	cout << p << endl;
	string s = "acc";
	while (p > 0) {
		if (n <= f[p - 1]) {
			p = p - 1;
		}
		else if (n <= f[p - 1] + (1 + p + 2)) {
			if (n == f[p - 1] + 1) {
				cout << 'a';
				return 0;
			}
			else {
				cout << 'c';
				return 0;
			}
		}
		else {
			n -= f[p - 1] + (1 + p + 2);
			p = p - 1;
		}
	}

	cout << s[n - 1] << endl;

	return 0;
}