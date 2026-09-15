#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    long long x, y;
};

struct Segment {
    Point a, b;
};

// 점 C가 방향 A → B의 어느 쪽에 있는지 반환
int ccw(const Point& a, const Point& b, const Point& c) {
    long long cross =
        (b.x - a.x) * (c.y - a.y) -
        (b.y - a.y) * (c.x - a.x);

    if (cross > 0) return 1;
    if (cross < 0) return -1;
    return 0;
}

bool intersects(const Segment& s1, const Segment& s2) {
    const Point& a = s1.a;
    const Point& b = s1.b;
    const Point& c = s2.a;
    const Point& d = s2.b;

    // x좌표 범위가 떨어져 있으면 만나지 않음
    if (max(a.x, b.x) < min(c.x, d.x) ||
        max(c.x, d.x) < min(a.x, b.x)) {
        return false;
    }

    // y좌표 범위가 떨어져 있으면 만나지 않음
    if (max(a.y, b.y) < min(c.y, d.y) ||
        max(c.y, d.y) < min(a.y, b.y)) {
        return false;
    }

    int c1 = ccw(a, b, c);
    int c2 = ccw(a, b, d);
    int c3 = ccw(c, d, a);
    int c4 = ccw(c, d, b);

    // 끝점 접촉과 일직선 위 겹침도 포함
    return c1 * c2 <= 0 && c3 * c4 <= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Segment> segments(n);

    for (auto& s : segments) {
        cin >> s.a.x >> s.a.y >> s.b.x >> s.b.y;
    }

    long long answer = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (intersects(segments[i], segments[j])) {
                ++answer;
            }
        }
    }

    cout << answer << '\n';
    return 0;
}
