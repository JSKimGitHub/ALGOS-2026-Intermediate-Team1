#include <iostream>
#include <vector>
using namespace std;

struct Point {              //점의 x,y좌표
    long long x, y;
};

struct Segment {            //선분을 표현하는 Segment
    Point a, b;
};

int ccw(const Point& a, const Point& b, const Point& c) {
    long long cross =
        (b.x - a.x) * (c.y - a.y) -
        (b.y - a.y) * (c.x - a.x);

    if (cross > 0) return 1;
    if (cross < 0) return -1;
    return 0;
}

bool intersects(const Segment& s1, const Segment& s2) {
    int c1 = ccw(s1.a, s1.b, s2.a);
    int c2 = ccw(s1.a, s1.b, s2.b);
    int c3 = ccw(s2.a, s2.b, s1.a);
    int c4 = ccw(s2.a, s2.b, s1.b);

    return c1 * c2 < 0 && c3 * c4 < 0;
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

    int answer = 0;

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
