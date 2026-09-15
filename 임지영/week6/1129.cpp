#include <iostream>
using namespace std;

long long X1[25], Y1[25], X2[25], Y2[25];

long long ccw(long long ax, long long ay, long long bx, long long by, long long cx, long long cy) {
    return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
}

bool isCross(int i, int j) {
    long long d1 = ccw(X1[i], Y1[i], X2[i], Y2[i], X1[j], Y1[j]);
    long long d2 = ccw(X1[i], Y1[i], X2[i], Y2[i], X2[j], Y2[j]);
    long long d3 = ccw(X1[j], Y1[j], X2[j], Y2[j], X1[i], Y1[i]);
    long long d4 = ccw(X1[j], Y1[j], X2[j], Y2[j], X2[i], Y2[i]);
    return (d1 * d2 < 0) && (d3 * d4 < 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while (cin >> N) {
        for (int i = 0; i < N; i++) {
            cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
        }

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (isCross(i, j)) cnt++;
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}