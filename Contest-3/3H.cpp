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
#define int long long
//const ll inf = (ll)1e18;
const int N = 1e6 + 1;
const int M = 20;
const int MAX = 1;

signed main() {
	int n;
	cin >> n;

	vector<int> P(n + 2);
	for (int i = 1; i <= n; ++i)
		cin >> P[i];

    // First greater element to the right
	vector<int> R(n + 2, n + 1);
	stack<int> st;
	for (int i = n; i >= 1; --i) {
		while (!st.empty() && P[st.top()] <= P[i])
			st.pop();
		if (!st.empty())
			R[i] = st.top();
		st.push(i);
	}
    
    // First greater element to the left
	vector<int> L(n + 2, 0);
	st = stack<int>();
	for (int i = 1; i <= n; ++i) {
		while (!st.empty() && P[st.top()] <= P[i]) 
			st.pop();
		if (!st.empty())
			L[i] = st.top();
		st.push(i);
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (L[i] == 0 && R[i] == n+1) continue;

        // [far...L....i...R...far2]
        int far = L[i] - 1;
        int far2 = R[i] + 1;

        if(L[i] == 0)
            far = 0;
        if(R[i] == n + 1)
            far2 = n + 1;

        if(far > 0 && P[far] < P[i]){
            while(far > 0 && P[far] < P[i]) far = L[far];
        }

        if(far2 < n+1 && P[far2] < P[i]){
            while(far2 < n + 1 && P[far2] < P[i]) far2 = R[far2];
        }

        // while (far > 0 && P[far] < P[i]) far--;
		// while (far2 < n && P[far2] < P[i]) far2++;

		// cout << P[i] << " :" << L[i] << " " << R[i] << " " << far << " " << far2 << endl;
		sum += P[i] * (L[i] - far) * (R[i] - i);

		sum += P[i] * (far2 - R[i]) * (i - L[i]);
	}

	cout << sum << endl;
	return 0;
}