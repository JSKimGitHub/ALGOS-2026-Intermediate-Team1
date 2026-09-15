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

int ccw(Point a, Point b, Point c) {
    long long cross = (b.x - a.x) * (c.y - a.y)
                    - (b.y - a.y) * (c.x - a.x);

    if (cross > 0) return 1;
    if (cross < 0) return -1;
    return 0;
}

bool intersects(const Segment& s, const Segment& t) {
    Point a = s.a, b = s.b;
    Point c = t.a, d = t.b;

    int abc = ccw(a, b, c);
    int abd = ccw(a, b, d);
    int cda = ccw(c, d, a);
    int cdb = ccw(c, d, b);

    // 같은 직선 위라면 실제 좌표 범위가 겹치는지 확인
    if (abc == 0 && abd == 0 && cda == 0 && cdb == 0) {
        return max(min(a.x, b.x), min(c.x, d.x))
                    <= min(max(a.x, b.x), max(c.x, d.x))
            && max(min(a.y, b.y), min(c.y, d.y))
                    <= min(max(a.y, b.y), max(c.y, d.y));
    }

    return abc * abd <= 0 && cda * cdb <= 0;
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
