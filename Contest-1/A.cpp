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


signed main() {
	string s;
	cin >> s;

	char c[N];
	for (int i = 0; i < s.length(); i++) {
		c[i] = s[i];
	}

	int len = s.length();
	int mid = (len - 1) / 2;

	int t;
	cin >> t;
	vector<int> v;
	while (t--) {
		int a;
		cin >> a;
		a--;
		if (a > mid) a = len - a - 1;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i <= mid; i++) {
		auto p = upper_bound(v.begin(), v.end(), i) - v.begin();
		if (p % 2 == 1) {
			swap(c[i], c[len - 1 - i]);
		}
	}

	for (int i = 0; i < s.length(); i++) {
		cout << c[i];
	}
	return 0;
}