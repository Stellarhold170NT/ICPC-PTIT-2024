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

signed main() {
	string a;
	string b;
	cin >> a >> b;

	int n = a.length();

	map<char, vector<int>> mp;
	map<char, vector<int>> mp2;

	for (int i = 0; i < n; i++) {
		mp[a[i]].push_back(i);
	}


	for (int i = 0; i < n; i++) {
		mp2[b[i]].push_back(i);
	}

	bool check = true;

	map<char, bool> vs;
	for (int i = 0; i < n; i++) {
		if (!vs[a[i]]) {
			if (a[i] != b[i]) {
				if (mp[a[i]] != mp2[b[i]]) {
					check = false;
				}
			}
		}
		vs[a[i]] = true;
	}


	if (check) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}