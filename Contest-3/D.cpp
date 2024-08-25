#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
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
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
#define ll long long

int main() {
	int n, m;
	cin >> n >> m;

	vector<ll> values(n);
	for (int i = 0; i < n; i++) {
		cin >> values[i];
	}

	map<ll, int> mp;
	mp[0] = 1;
	ll cnt = 0;
	ll sum = 0;

	for (int i = 0; i < n; i++) {
		sum += values[i] % m;
		sum = (sum + n) % m;
		cnt += mp[sum];
		mp[sum]++;
	}

	cout << cnt << endl;

	return 0;
}