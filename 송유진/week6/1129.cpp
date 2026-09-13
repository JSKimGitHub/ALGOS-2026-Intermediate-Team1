#include <iostream>
#include <vector>

using namespace std;

struct Point { long long x, y; };
struct Segment { Point p1, p2; };

int ccw(Point a, Point b, Point c) {
    long long op = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (op > 0) return 1;
    if (op < 0) return -1;
    return 0;
}

bool isStrictIntersect(Segment s1, Segment s2) {
    int ccw1 = ccw(s1.p1, s1.p2, s2.p1) * ccw(s1.p1, s1.p2, s2.p2);
    int ccw2 = ccw(s2.p1, s2.p2, s1.p1) * ccw(s2.p1, s2.p2, s1.p2);
    // 완전히 교차하는 점만 교점으로 인정
    return ccw1 < 0 && ccw2 < 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<Segment> segs(n);
    for (int i = 0; i < n; ++i) {
        cin >> segs[i].p1.x >> segs[i].p1.y >> segs[i].p2.x >> segs[i].p2.y;
    }
    
    int intersection_count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (isStrictIntersect(segs[i], segs[j])) {
                intersection_count++;
            }
        }
    }
    
    cout << intersection_count << "\n";
    return 0;
}
