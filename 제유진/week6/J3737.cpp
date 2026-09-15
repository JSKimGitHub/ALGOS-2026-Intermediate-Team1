#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    for (auto& row : board) cin >> row;

    vector<vector<int>> group(n, vector<int>(m, -1));
    vector<vector<pair<int, int>>> spots;

    // 1. X 덩어리 세 개 구분
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (board[r][c] != 'X' || group[r][c] != -1)
                continue;

            int id = spots.size();
            spots.push_back({});

            queue<pair<int, int>> q;
            q.push({r, c});
            group[r][c] = id;

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                spots[id].push_back({x, y});

                for (int d = 0; d < 4; ++d) {
                    int nx = x + dr[d];
                    int ny = y + dc[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;

                    if (board[nx][ny] != 'X' || group[nx][ny] != -1)
                        continue;

                    group[nx][ny] = id;
                    q.push({nx, ny});
                }
            }
        }
    }

    // dist[k][r][c]: k번 덩어리에서 해당 칸까지 칠할 최소 개수
    vector<vector<vector<int>>> dist(
        3, vector<vector<int>>(n, vector<int>(m, INF))
    );

    // 2. 각 덩어리에서 다중 시작점 0-1 BFS
    for (int k = 0; k < 3; ++k) {
        deque<pair<int, int>> dq;

        for (auto [r, c] : spots[k]) {
            dist[k][r][c] = 0;
            dq.push_back({r, c});
        }

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                int cost = (board[nr][nc] == '.');

                if (dist[k][nr][nc] > dist[k][r][c] + cost) {
                    dist[k][nr][nc] = dist[k][r][c] + cost;

                    if (cost == 0)
                        dq.push_front({nr, nc});
                    else
                        dq.push_back({nr, nc});
                }
            }
        }
    }

    // 3. 세 경로가 만나는 칸을 모두 확인
    int answer = INF;

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            int total = dist[0][r][c]
                      + dist[1][r][c]
                      + dist[2][r][c];

            // 만나는 '.' 칸을 세 번 셌으므로 두 번 빼기
            if (board[r][c] == '.') total -= 2;

            answer = min(answer, total);
        }
    }

    cout << answer << '\n';
    return 0;
}
