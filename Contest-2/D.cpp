#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <bitset>
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
//const int inf = 1000000000;
const ll inf = (ll)1e18;
const int N = 2000;

int d, n;
bool used[N] = { false };
int mt[N];
vector<int> ke[N];
vector<int> v;


int to10(const string& s) {
	int res = 0;
	int p = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '1') {
			res += (1LL << p);
		}
		p++;
	}
	return res;
}

int cntbit(int n) {
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		if (n & (1 << i)) {
			cnt++;
		}
	}
	return cnt;
}


bool kuhn(int s) {
	if (used[s]) return false;

	used[s] = true;
	for (auto v : ke[s]) {
		if (mt[v] == -1 || kuhn(mt[v])) {
			mt[v] = s;
			return true;
		}
	}

	return false;
}

signed main() {
	int d, n;
	cin >> d >> n;

	fill(mt, mt + n, -1);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(to10(s));
	}

	sort(v.begin(), v.end(), [](int a, int b) {
		return cntbit(a) > cntbit(b);
		});

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if ((v[i] & v[j]) == v[i]) {
				ke[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		memset(used, false, sizeof used);
		kuhn(i);
	}

	bool checked[N] = { false };


	int res = 0;
	for (int i = 0; i < n; i++) {
		if (!checked[i]) {
			res += cntbit(v[i]) + 1;
			int w = i;
			while (mt[w] != -1) {
				checked[w] = true;
				w = mt[w];
			}
			checked[w] = true;
		}
	}

	res -= 1;
	cout << res << endl;

	return 0;
}
