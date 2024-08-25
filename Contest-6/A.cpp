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
const int N = 5001;
const int M = 20;

int f[N];
int g[N];

void init() {
	f[0] = 0;
	f[1] = 1;

	g[0] = 0;
	g[1] = 1;

	for (int i = 2; i < N; i++) {
		g[i] = i;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				g[i] = min(g[i], g[j] + 2 + g[i / j]);
			}
		}
	}

	for (int i = 2; i < N; i++) {
		f[i] = g[i];
		for (int j = 1; j < i; j++) {
			f[i] = min(f[i], f[j] + 2 + f[i - j]);
		}
	}
}

signed main() {
	init();
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		cout << f[n] << endl;
	}
	return 0;
}