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

// 양수면 1, 음수면 -1, 일직선이면 0
int ccw(Point a, Point b, Point c) {
    long long cross =
        (b.x - a.x) * (c.y - a.y)
        - (b.y - a.y) * (c.x - a.x);

    if (cross > 0) return 1;
    if (cross < 0) return -1;
    return 0;
}

bool intersects(const Segment& s1, const Segment& s2) {
    Point a = s1.a, b = s1.b;
    Point c = s2.a, d = s2.b;

    int abC = ccw(a, b, c);
    int abD = ccw(a, b, d);
    int cdA = ccw(c, d, a);
    int cdB = ccw(c, d, b);

    // 두 선분이 같은 직선 위에 있는 경우
    if (abC == 0 && abD == 0 && cdA == 0 && cdB == 0) {
        return max(min(a.x, b.x), min(c.x, d.x))
                   <= min(max(a.x, b.x), max(c.x, d.x))
            && max(min(a.y, b.y), min(c.y, d.y))
                   <= min(max(a.y, b.y), max(c.y, d.y));
    }

    // 서로의 직선을 기준으로 양 끝점이 반대쪽에 있으면 교차
    return abC * abD <= 0 && cdA * cdB <= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Segment> segments(n);

    for (int i = 0; i < n; ++i) {
        cin >> segments[i].a.x >> segments[i].a.y
            >> segments[i].b.x >> segments[i].b.y;
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
}
