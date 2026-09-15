#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct Point {
    long long x, y;

    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// 양수: 반시계 방향
// 음수: 시계 방향
// 0: 일직선
long long ccw(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y)
         - (b.y - a.y) * (c.x - a.x);
}

vector<Point> convexHull(vector<Point> points) {
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    if (points.size() <= 1) return points;

    vector<Point> lower, upper;

    // 아래쪽 껍질: 왼쪽 → 오른쪽
    for (const Point& p : points) {
        while (lower.size() >= 2 &&
               ccw(lower[lower.size() - 2], lower.back(), p) <= 0) {
            lower.pop_back();
        }

        lower.push_back(p);
    }

    // 위쪽 껍질: 오른쪽 → 왼쪽
    for (int i = static_cast<int>(points.size()) - 1; i >= 0; --i) {
        const Point& p = points[i];

        while (upper.size() >= 2 &&
               ccw(upper[upper.size() - 2], upper.back(), p) <= 0) {
            upper.pop_back();
        }

        upper.push_back(p);
    }

    // 양쪽 끝점이 중복되므로 하나씩 제거
    lower.pop_back();
    upper.pop_back();

    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);

    for (Point& p : points) {
        cin >> p.x >> p.y;
    }

    vector<Point> hull = convexHull(points);

    // 넓이의 2배를 정수로 계산
    long long area2 = 0;
    int m = static_cast<int>(hull.size());

    for (int i = 0; i < m; ++i) {
        int j = (i + 1) % m;

        area2 += hull[i].x * hull[j].y
               - hull[i].y * hull[j].x;
    }

    area2 = abs(area2);

    cout << area2 / 2;
    if (area2 % 2 == 1) cout << ".5";
    cout << '\n';

    return 0;
}
