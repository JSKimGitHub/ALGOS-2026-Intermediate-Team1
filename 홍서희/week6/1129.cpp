#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

struct Segment {
    Point p1, p2;
};

int ccw(Point a, Point b, Point c) {
    long long op = a.x * b.y + b.x * c.y + c.x * a.y;
    op -= (a.y * b.x + b.y * c.x + c.y * a.x);
    if (op > 0) return 1;
    if (op < 0) return -1;
    return 0;
}

bool isIntersect(Segment s1, Segment s2) {
    Point a = s1.p1;
    Point b = s1.p2;
    Point c = s2.p1;
    Point d = s2.p2;

    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);

    if (ab == 0 && cd == 0) {
        if (max(a.x, b.x) < min(c.x, d.x) || max(c.x, d.x) < min(a.x, b.x)) return false;
        if (max(a.y, b.y) < min(c.y, d.y) || max(c.y, d.y) < min(a.y, b.y)) return false;
        return true;
    }

    return ab <= 0 && cd <= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Segment> segs(n);
    for (int i = 0; i < n; i++) {
        cin >> segs[i].p1.x >> segs[i].p1.y >> segs[i].p2.x >> segs[i].p2.y;
    }

    int intersectCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isIntersect(segs[i], segs[j])) {
                intersectCount++;
            }
        }
    }

    cout << intersectCount << "\n";

    return 0;
}
