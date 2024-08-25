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

signed main() {
	int n;
	cin >> n;

	unordered_map<string, int> mp;

	for (int i = 1; i <= n; i++) {
		vector<char> v;
		for (int j = 1; j <= 10; j++) {
			char c;
			cin >> c;
			v.push_back(c);
		}
		sort(v.begin(), v.end());
		string s = "";
		for (auto x : v) s = s + x;
		mp[s]++;
	}

	int res = 0;
	for (auto x : mp) {
		res += x.second * (x.second - 1) / 2;
	}

	cout << res << endl;

	return 0;
}