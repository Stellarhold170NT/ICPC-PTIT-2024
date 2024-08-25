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
const int inf = 1000000000;
//#define int long long
//const ll inf = (ll)1e18;
const double eps = 1e-9;
const int N = 2500 + 1;
const int M = 20;
const int MAX = 1;

void swap(int* a1, int* a2) {
	int t = *a1;
	*a1 = *a2;
	*a2 = t;
}

int main() {

	int a1, a2, b1, b2, c1, c2;

	scanf("%d %d", &a1, &a2);
	scanf("%d %d", &b1, &b2);
	scanf("%d %d", &c1, &c2);


	if (a1 < a2) swap(&a1, &a2);
	if (b1 < b2) swap(&b1, &b2);
	if (c1 < c2) swap(&c1, &c2);

	if (b1 > a1) {
		swap(&b1, &a1);
		swap(&b2, &a2);
	}

	if (c1 > a1) {
		swap(&c1, &a1);
		swap(&c2, &a2);
	}

	if (c1 > b1) {
		swap(&c1, &b1);
		swap(&c2, &b2);
	}

	int c = a1;

	/*
		+ TH1:
			._______.
			|_______|
			|_______|
			|_______|
		+ TH2:
			.__.____.
			|  |    |
			|  |----|
			|__|____|
	*/

	if (((b1 + c1 == c && b2 == c2) || (b1 + c2 == c && b2 == c1) || (c2 + b2 == c && c1 == b1))
		|| ((a1 == c && b1 == c && c1 == c && a2 + b2 + c2 == c))) {
		cout << c << endl;
	}
	else {
		cout << 0 << endl;
	}

	return 0;
}