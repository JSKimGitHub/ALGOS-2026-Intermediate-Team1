#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

struct Point {
    long long x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);

    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    int answer = 1;

    for (int i = 0; i < n; ++i) {
        unordered_map<unsigned long long, int> cnt;
        cnt.reserve((n - i) * 2);

        // i보다 뒤에 있는 점만 비교
        for (int j = i + 1; j < n; ++j) {
            long long dx = points[j].x - points[i].x;
            long long dy = points[j].y - points[i].y;

            long long g = gcd(dx < 0 ? -dx : dx,
                              dy < 0 ? -dy : dy);

            dx /= g;
            dy /= g;

            // 방향이 반대여도 같은 직선으로 처리
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }

            unsigned long long key =
                (static_cast<unsigned long long>(
                    static_cast<unsigned int>(dx)) << 32)
                | static_cast<unsigned int>(dy);

            answer = max(answer, ++cnt[key] + 1);
        }
    }

    cout << answer << '\n';
    return 0;
}
