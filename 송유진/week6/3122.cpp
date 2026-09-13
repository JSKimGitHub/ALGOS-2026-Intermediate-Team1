#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point { long long x, y; };
struct Segment { Point p1, p2; };

int ccw(Point a, Point b, Point c) {
    long long op = a.x*b.y + b.x*c.y + c.x*a.y - (a.y*b.x + b.y*c.x + c.y*a.x);
    if (op > 0) return 1;
    if (op < 0) return -1;
    return 0;
}

bool isIntersect(Segment s1, Segment s2) {
    Point a = s1.p1, b = s1.p2, c = s2.p1, d = s2.p2;
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    
    // 일직선 상에 위치하는 경우 (포개짐 여부 확인)
    if (ab == 0 && cd == 0) {
        if (make_pair(a.x, a.y) > make_pair(b.x, b.y)) swap(a, b);
        if (make_pair(c.x, c.y) > make_pair(d.x, d.y)) swap(c, d);
        return make_pair(a.x, a.y) <= make_pair(d.x, d.y) && make_pair(c.x, c.y) <= make_pair(b.x, b.y);
    }
    // 일반적인 교차 또는 끝점 접촉
    return ab <= 0 && cd <= 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<Segment> segs(n);
    for (int i = 0; i < n; ++i) {
        cin >> segs[i].p1.x >> segs[i].p1.y >> segs[i].p2.x >> segs[i].p2.y;
    }
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (isIntersect(segs[i], segs[j])) {
                ans++;
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
