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
#define int long long
typedef array<int, 3> triple;
const ll mod = (ll)1e9 + 7;
const int inf = 1000000000;
//const ll inf = (ll)1e18;
const int N = 2e5 + 1;
const int M = 20;

int imax = INT_MAX;
int leni = to_string(imax).length();
string istr = to_string(imax);

int lmax = LLONG_MAX;
int len = to_string(lmax).length();
string lstr = to_string(lmax);

int ucln(int a, int b) {
	if (!b) return a;
	return ucln(b, a % b);
}

bool isNumber(string t) {
	if (t.length() > len || t.length() < leni) return false;
	for (auto c : t) {
		int d = c - '0';
		if (d >= 0 && d <= 9) {
			continue;
		}
		else return false;
	}
	if (t.length() == len) {
		if (t.compare(lstr) <= 0)
			return true;
		else return false;
	}
	else if (t.length() == leni) {
		if (t.compare(istr) > 0)
			return true;
		else return false;
	}
	return true;
}

signed main() {
	string s;

	int res = 0;
	while (cin >> s) {
		if (isNumber(s)) {
			int a = stoll(s);
			res += a;
		}
	}
	cout << res << endl;


	return 0;
}