#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minPresses(int N, int ST, int EN, int u, int d) {
    vector<int> visited(N + 1, -1);
    queue<int> q;

    q.push(ST);
    visited[ST] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == EN) {
            return visited[current];
        }

        if (current + u <= N && visited[current + u] == -1) {
            visited[current + u] = visited[current] + 1;
            q.push(current + u);
        }

        if (current - d >= 1 && visited[current - d] == -1) {
            visited[current - d] = visited[current] + 1;
            q.push(current - d);
        }
    }

    return -1;
}

int main() {
    int N, ST, EN, u, d;
    cin >> N >> ST >> EN >> u >> d;

    int result = minPresses(N, ST, EN, u, d);

    cout << result << endl;

    return 0;
}
