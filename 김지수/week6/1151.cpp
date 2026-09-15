#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    long long x, y;
};

// 양수: 반시계 방향
// 음수: 시계 방향
// 0: 일직선
long long ccw(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y)
         - (b.y - a.y) * (c.x - a.x);
}

vector<Point> convexHull(vector<Point> points) {
    // x좌표 우선, 같으면 y좌표로 정렬
    sort(points.begin(), points.end(),
         [](const Point& a, const Point& b) {
             if (a.x != b.x) return a.x < b.x;
             return a.y < b.y;
         });

    // 같은 좌표의 점 제거
    points.erase(
        unique(points.begin(), points.end(),
               [](const Point& a, const Point& b) {
                   return a.x == b.x && a.y == b.y;
               }),
        points.end()
    );

    if (points.size() <= 2) {
        return points;
    }

    vector<Point> lower, upper;

    // 아래쪽 테두리
    for (const Point& p : points) {
        while (lower.size() >= 2 &&
               ccw(lower[lower.size() - 2], lower.back(), p) <= 0) {
            lower.pop_back();
        }

        lower.push_back(p);
    }

    // 위쪽 테두리
    for (int i = static_cast<int>(points.size()) - 1; i >= 0; --i) {
        const Point& p = points[i];

        while (upper.size() >= 2 &&
               ccw(upper[upper.size() - 2], upper.back(), p) <= 0) {
            upper.pop_back();
        }

        upper.push_back(p);
    }

    // 양 끝점은 두 테두리에 중복되므로 하나씩 제거
    lower.pop_back();
    upper.pop_back();

    // 아래쪽 테두리 뒤에 위쪽 테두리를 연결
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

    // 점이 3개 미만이면 넓이는 0
    if (hull.size() < 3) {
        cout << 0 << '\n';
        return 0;
    }

    long long twiceArea = 0;
    int m = static_cast<int>(hull.size());

    for (int i = 0; i < m; ++i) {
        int next = (i + 1) % m;

        twiceArea += hull[i].x * hull[next].y
                   - hull[i].y * hull[next].x;
    }

    if (twiceArea < 0) {
        twiceArea = -twiceArea;
    }

    cout << twiceArea / 2;

    if (twiceArea % 2 != 0) {
        cout << ".5";
    }

    cout << '\n';
    return 0;
}
