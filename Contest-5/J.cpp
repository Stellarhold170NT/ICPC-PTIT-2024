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
#define scd(n) scanf("%d", &n);
#define sclld(n) scanf("%lld", &n);
#define sclld2(n, m) scanf("%lld %lld", &n, &m);
#define sclld3(n, m, k) scanf("%lld %lld %lld", &n, &m, &k);
#define pii pair<int, int>
#define ll long long
typedef array<int, 3> triple;
ll mod = (ll)1e9 + 7;
//const int inf = 1000000000;
#define int long long
const ll inf = (ll)1e18;
const int N = 2e5 + 1;
const int logN = 18;
const int M = 20;
const int MAX = 1;

int n;
int arr[N];
struct DATA {
	int a, b;
};

DATA tree1[N << 2];
int tree2[N << 2];

void merge(int id) {
	tree1[id].a = min(tree1[id * 2].a, tree1[id * 2 + 1].a);
	vector<int> v;
	v.push_back(tree1[id * 2].a);
	v.push_back(tree1[id * 2].b);
	v.push_back(tree1[id * 2 + 1].a);
	v.push_back(tree1[id * 2 + 1].b);
	sort(v.begin(), v.end());
	tree1[id].b = v[1];
}

DATA merge(DATA a, DATA b) {
	int min1 = min(a.a, b.a);
	vector<int> v;
	v.push_back(a.a);
	v.push_back(a.b);
	v.push_back(b.a);
	v.push_back(b.b);
	sort(v.begin(), v.end());
	int min2 = v[1];
	return { min1, min2 };
}

void build(int id, int l, int r) {
	if (l > r) return;
	if (l == r) {
		tree1[id].a = arr[l];
		tree1[id].b = INT_MAX;
		tree2[id] = arr[l];
		return;
	}

	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	tree2[id] = max(tree2[id * 2], tree2[id * 2 + 1]);
	merge(id);
}

int queryMax(int id, int l, int r, int u, int v) {
	if (l > r || r < u || l > v) return 0;
	if (l >= u && r <= v) {
		return tree2[id];
	}
	int mid = (l + r) / 2;
	return max(queryMax(id * 2, l, mid, u, v), queryMax(id * 2 + 1, mid + 1, r, u, v));
}

DATA queryData(int id, int l, int r, int u, int v) {
	if (l > r || r < u || l > v) return { INT_MAX, INT_MAX };
	if (l >= u && r <= v) {
		return tree1[id];
	}
	int mid = (l + r) / 2;
	auto a = queryData(id * 2, l, mid, u, v);
	auto b = queryData(id * 2 + 1, mid + 1, r, u, v);
	return merge(a, b);
}

signed main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	build(1, 1, n);

	int l = 1;
	int r = 3;
	int ans = 0;
	while (r <= n) {
		auto dt = queryData(1, 1, n, l, r);
		int mx = queryMax(1, 1, n, l, r);
		if (dt.a + dt.b > mx) {
			ans = max(ans, r - l + 1);
			r++;
		}
		else {
			l++;
			if (r - l + 1 < 3) r++;
		}
	}

	cout << ans << endl;

	return 0;
}