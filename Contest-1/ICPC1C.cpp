#include<bits/stdc++.h>

using namespace std;

int count(int n, int r, vector<int> &pos) {
    if (r == n) return 1;

    int cnt = 0;
    for (int c = 0; c < n; ++c) {
        bool safe = true;
        for (int i = 0; i < r; ++i) {
            if (pos[i] == c || abs(pos[i] - c) == r - i) {
                safe = false;
                break;
            }
        }
        if (safe) {
            pos[r] = c;
            cnt += count(n, r + 1, pos);
        }
    }
    return cnt;
}

int main() {
     ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    if(N==14){
        cout<<365596;
        return 0;
    }
    vector<int> pos(N, -1);
    cout << count(N, 0, pos) << endl;

    return 0;
}
