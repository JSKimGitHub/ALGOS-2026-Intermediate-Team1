#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
    
    bool operator<=(const Point& other) const {
        if (x == other.x) return y <= other.y;
        return x < other.x;
    }
};

struct Segment {
    Point p1, p2;
};


int ccw(Point p1, Point p2, Point p3) {
    long long temp = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    if (temp > 0) return 1;
    if (temp < 0) return -1;
    return 0;
}

bool isIntersect(Segment s1, Segment s2) {
    Point A = s1.p1;
    Point B = s1.p2;
    Point C = s2.p1;
    Point D = s2.p2;

    int abc = ccw(A, B, C);
    int abd = ccw(A, B, D);
    int cda = ccw(C, D, A);
    int cdb = ccw(C, D, B);

    if (abc * abd == 0 && cda * cdb == 0) {
        if (B <= A) swap(A, B);
        if (D <= C) swap(C, D);
        return (A <= D && C <= B);
    }
    return (abc * abd <= 0) && (cda * cdb <= 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Segment> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].p1.x >> segments[i].p1.y >> segments[i].p2.x >> segments[i].p2.y;
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isIntersect(segments[i], segments[j])) {
                ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
