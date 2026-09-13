#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};
Point p0;

long long ccw(Point a, Point b, Point c) {
    long long value = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (value > 0) return 1;
    if (value < 0) return -1;
    return 0;
}

long long distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool compare(Point p1, Point p2) {
    long long order = ccw(p0, p1, p2);
    if (order == 0) {
        return distSq(p0, p1) < distSq(p0, p2);
    }
    return order > 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Point> pts(n);
    int min_idx = 0;

    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
        if (pts[i].y < pts[min_idx].y || (pts[i].y == pts[min_idx].y && pts[i].x < pts[min_idx].x)) {
            min_idx = i;
        }
    }

    swap(pts[0], pts[min_idx]);
    p0 = pts[0];

    sort(pts.begin() + 1, pts.end(), compare);

    vector<Point> hull;
    for (int i = 0; i < n; i++) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), pts[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }

    long long area2 = 0;
    int hull_size = hull.size();
    for (int i = 0; i < hull_size; i++) {
        Point current = hull[i];
        Point next = hull[(i + 1) % hull_size];
        area2 += (current.x * next.y) - (next.x * current.y);
    }

    area2 = abs(area2);

    if(area2 % 2 == 0) cout<< area2 / 2 << "\n";
    else cout << area2 / 2 << ".5\n";

    return 0;
}
