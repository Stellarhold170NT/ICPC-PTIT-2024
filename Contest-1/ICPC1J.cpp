#include<bits/stdc++.h>
using namespace std;

vector<int> maxMins(vector<int>& a) {
    int n = a.size();
    vector<int> l(n), r(n);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && a[s.top()] >= a[i]) s.pop();
        if (s.empty()) {
            l[i] = -1;
        } else {
            l[i] = s.top();
        }
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && a[s.top()] >= a[i]) s.pop();
        if (s.empty()) {
            r[i] = n;
        } else {
            r[i] = s.top();
        }
        s.push(i);
    }
    vector<int> res(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int len = r[i] - l[i] - 1;
        res[len] = max(res[len], a[i]);
    }
    for (int i = n - 1; i >= 1; --i) {
        res[i] = max(res[i], res[i + 1]);
    }

    return vector<int>(res.begin() + 1, res.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> res = maxMins(a);
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    return 0;
}
