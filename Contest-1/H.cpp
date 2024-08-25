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
const int inf = 1000000000;
//const ll inf = (ll)1e18;
const int N = 2e5 + 1;
const int M = 20;

int ucln(int a, int b) {
	if (!b) return a;
	return ucln(b, a % b);
}

signed main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int arr[N];
		vector<int> range(1e6 + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			range[arr[i]]++;
		}

		for (int i = 1e6; i >= 1; i--) {
			int cnt = 0;
			for (int p = i; p <= 1e6; p += i) {
				cnt += range[p];
			}
			if (cnt > 1) {
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}