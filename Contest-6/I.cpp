#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits.h>
#include <cmath>

using namespace std;

const int INF = INT_MAX;

struct Position {
    int x, y;
};

vector<Position> apples;
vector<Position> doors;
vector<vector<char>> garden;
int N, M;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
bool isValid(int x, int y) {
    return x >= 0 && x < N&& y >= 0 && y < M&& garden[x][y] != '#';
}
vector<vector<int>> bfs(Position start) {
    vector<vector<int>> dist(N, vector<int>(M, INF));
    queue<Position> q;
    dist[start.x][start.y] = 0;
    q.push(start);

    bool flag = false;

    while (!q.empty()) {
        Position curr = q.front();
        q.pop();
        int currDist = dist[curr.x][curr.y];
        for (int i = 0; i < 4; ++i) {
            int newX = curr.x + dx[i];
            int newY = curr.y + dy[i];

            if (isValid(newX, newY) && dist[newX][newY] > currDist + 1) {
                dist[newX][newY] = currDist + 1;
                q.push({ newX, newY });
            }
        }
        if (!flag && garden[curr.x][curr.y] == 'D') {
            for (const auto& door : doors) {
                if (dist[door.x][door.y] > currDist) {
                    dist[door.x][door.y] = currDist;
                    q.push(door);
                }
            }
            flag = true;
        }
    }
    return dist;
}
int tsp(int pos, int visited, vector<vector<int>>& dp, vector<vector<int>>& distMatrix, vector<vector<bool>>& used) {
    if (visited == (1 << apples.size()) - 1) {
        return 0;
    }
    if (used[pos][visited]) {
        return dp[pos][visited];
    }

    int answer = INF;
    for (int i = 0; i < apples.size(); ++i) {
        if (!(visited & (1 << i))) {
            answer = min(answer, distMatrix[pos][i] + tsp(i, visited | (1 << i), dp, distMatrix, used));
        }
    }
    used[pos][visited] = true;
    return dp[pos][visited] = answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    garden.assign(N, vector<char>(M));
    vector<vector<vector<int>>> dists;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> garden[i][j];
            if (garden[i][j] == 'A') {
                apples.push_back({ i, j });
            }
            else if (garden[i][j] == 'D') {
                doors.push_back({ i, j });
            }
        }
    }

    int K = apples.size();
    vector<vector<int>> distMatrix(K, vector<int>(K, INF));
    for (int i = 0; i < K; ++i) {
        dists.push_back(bfs(apples[i]));
        for (int j = 0; j < K; ++j) {
            distMatrix[i][j] = dists[i][apples[j].x][apples[j].y];
            if (distMatrix[i][j] == INF) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    vector<vector<int>> dp(K, vector<int>(1 << K, -1));
    vector<vector<bool>> used(K, vector<bool>(1 << K, false));
    int answer = INF;
    for (int i = 0; i < K; ++i) {
        answer = min(answer, tsp(i, 1 << i, dp, distMatrix, used));
    }

    cout << answer << endl;
    return 0;
}