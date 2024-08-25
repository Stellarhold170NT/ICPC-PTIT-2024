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
#include <bitset>
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

int par[N];
int Size[N];
bool visited[N] = { false };
int n, m;

void init() {
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		Size[i] = 1;
	}
}

int find(int u) {
	if (par[u] != u) par[u] = find(par[u]);
	return par[u];
}

bool connect(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	if (Size[u] < Size[v]) swap(u, v);
	Size[u] += Size[v];
	par[v] = u;
	return true;
}
signed main() {
	cin >> n >> m;
	init();

	vector<int> edge[N];
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	vector<int> p(n);
	for (int i = 0; i < n; i++) cin >> p[i];

	int tplt = 0;
	vector<string> res(n, "NO");
	for (int i = n - 1; i >= 0; i--) {
		int u = p[i];
		visited[u] = true;
		tplt++;

		for (auto v : edge[u]) {
			if (visited[v]) {
				if (connect(u, v)) {
					tplt--;
				}
			}
		}

		if (tplt == 1) res[i] = "YES";
	}

	for (int i = 0; i < n; i++) cout << res[i] << endl;

	return 0;
}