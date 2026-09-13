#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point { long long x, y; };

bool compare(Point a, Point b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

long long ccw(Point a, Point b, Point c) {
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<Point> pts(n);
    for (int i = 0; i < n; ++i) cin >> pts[i].x >> pts[i].y;
    
    sort(pts.begin(), pts.end(), compare);
    
    vector<Point> lower, upper;
    for (int i = 0; i < n; ++i) {
        while (lower.size() >= 2 && ccw(lower[lower.size()-2], lower.back(), pts[i]) <= 0) 
            lower.pop_back();
        lower.push_back(pts[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        while (upper.size() >= 2 && ccw(upper[upper.size()-2], upper.back(), pts[i]) <= 0) 
            upper.pop_back();
        upper.push_back(pts[i]);
    }
    
    vector<Point> hull = lower;
    for (size_t i = 1; i < upper.size() - 1; ++i) hull.push_back(upper[i]);
    
    long long area2 = 0;
    for (size_t i = 0; i < hull.size(); ++i) {
        size_t j = (i + 1) % hull.size();
        area2 += hull[i].x * hull[j].y - hull[j].x * hull[i].y;
    }
    area2 = abs(area2);
    
    // 정수면 정수만, 아니면 .5를 붙여 출력
    if (area2 % 2 == 0) cout << area2 / 2 << "\n";
    else cout << area2 / 2 << ".5\n";
    
    return 0;
}
