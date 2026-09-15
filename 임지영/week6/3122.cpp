#include <iostream>
using namespace std;

const int MAXN = 10005;
long long SX[MAXN], SY[MAXN], EX[MAXN], EY[MAXN];

long long ccw(long long ax, long long ay, long long bx, long long by, long long cx, long long cy) {
    return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
}

bool onSegment(long long px, long long py, long long qx, long long qy, long long rx, long long ry) {
    // p, q, r가 이미 콜리니어인 상태에서 q가 선분 pr 위에 있는지 체크
    return min(px, rx) <= qx && qx <= max(px, rx) &&
           min(py, ry) <= qy && qy <= max(py, ry);
}

bool isIntersect(int i, int j) {
    long long ax = SX[i], ay = SY[i], bx = EX[i], by = EY[i];
    long long cx = SX[j], cy = SY[j], dx = EX[j], dy = EY[j];

    long long d1 = ccw(cx, cy, dx, dy, ax, ay);
    long long d2 = ccw(cx, cy, dx, dy, bx, by);
    long long d3 = ccw(ax, ay, bx, by, cx, cy);
    long long d4 = ccw(ax, ay, bx, by, dx, dy);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
        return true; // 일반적인 교차
    }

    // 콜리니어/끝점 접촉 케이스
    if (d1 == 0 && onSegment(cx, cy, ax, ay, dx, dy)) return true;
    if (d2 == 0 && onSegment(cx, cy, bx, by, dx, dy)) return true;
    if (d3 == 0 && onSegment(ax, ay, cx, cy, bx, by)) return true;
    if (d4 == 0 && onSegment(ax, ay, dx, dy, bx, by)) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> SX[i] >> SY[i] >> EX[i] >> EY[i];
    }

    long long cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (isIntersect(i, j)) cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}