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
#include <complex>
#include <numeric>
#include <unordered_set>
#include <array>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define stp(n) fixed << setprecision(n)
#define scd(n) scanf("%d", &n);
#define sclld(n) scanf("%lld", &n);
#define sclld2(n, m) scanf("%lld %lld", &n, &m);
#define sclld3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c);
#define pii pair<int, int>
#define ll long long
typedef array<int, 3> triple;
const ll mod = (ll)(1e9 + 7);
#define int long long
const ll inf = (ll)1e9;
//const ll inf = (ll)1e18;
#define A (ll)911382323
//#define A (ll)131
#define B (ll)972663749
//#define A (ll)3
//#define B (ll)97
const int N = 2e5 + 1;
const int M = 1000;
const int MAX = 1;

bool isLucky(int w) {
	while (w) {
		if (w % 10 == 7 || w % 10 == 4) {
			w /= 10;
			continue;
		}
		else return false;
	}
	return true;
}

int n;
vector<int> edge[N];
vector<pair<int, int>> v;
map<pair<int, int>, int> mp;
int tplt[N] = { 0 };
int sz[N] = { 0 };
bool visited[N] = { false };

int dfs(int s, int par, int t) {
	visited[s] = true;
	tplt[s] = t;
	int sz = 1;
	for (auto x : edge[s]) {
		if (x != par && !mp[{x, s}]) {
			sz += dfs(x, s, t);
		}
	}
	return sz;
}

signed main() {
	cin >> n;

	for (int i = 1; i <= n - 1; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edge[a].push_back(b);
		edge[b].push_back(a);
		if (isLucky(w)) {
			v.push_back({ a, b });
			mp[{a, b}] = true;
			mp[{b, a}] = true;
		}
	}

	int tp = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			tp++;
			int S = dfs(i, 0, tp);
			sz[tp] = n - S;
		}
	}

	ll res = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = sz[tplt[i]];
		res += cnt * (cnt - 1);
	}

	cout << res << endl;


	return 0;
}