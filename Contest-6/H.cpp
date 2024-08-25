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
const int N = 2e7 + 1;
const int M = 20;
const double mul = 1e6;

int prime[N];
int f[N] = { 0 };

void init() {
	for (int i = 2; i * i <= N; i++) {
		if (prime[i] == 0) {
			for (int j = i * i; j < N; j += i) {
				if (prime[j] == 0) {
					prime[j] = i;
				}
				f[j] = 1;
			}
		}
	}

	for (int i = 2; i < N; i++) {
		if (prime[i] == 0) prime[i] = i;
	}
}

int ucln(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

signed main() {
	init();
	int n;
	cin >> n;

	vector<int> v(n);

	unordered_map<int, bool> mp;
	bool check = true;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		if (i > 0 && v[i] > 0 && v[i - 1] > 0) {
			int u = ucln(v[i], v[i - 1]);
			if (u > 1)
				check = false;

		}

		if (i > 0 && v[i] == 0 && v[i - 1] == 0) {
			check = false;
		}

		if (!check) {
			cout << -1 << endl;
			return 0;
		}
	}

	bool zeroExisted = false;
	bool gtExisted = false;
	for (int i = 0; i < n; i++) {
		if (v[i] == 0) {
			zeroExisted = true;
		}
		if (v[i] == 1) {
			gtExisted = true;
		}

		if ((i > 0 && v[i - 1] == 0) || (i <= n - 2 && v[i + 1] == 0)) {
			while (v[i] > 1) {
				mp[prime[v[i]]] = 1;
				v[i] /= prime[v[i]];
			}
		}
	}

	if (gtExisted) {
		cout << -1 << endl;
		return 0;
	}

	if (!zeroExisted) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 2; i < N; i++) {
		if (f[i] == 0 && mp[i] == false) {
			cout << i << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}