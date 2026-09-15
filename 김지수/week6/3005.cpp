#include <iostream>
#include <vector>
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

    // 다각형 넓이의 2배를 저장
    long long twiceArea = 0;

    for (int i = 0; i < n; ++i) {
        // 마지막 점의 다음은 첫 번째 점
        int next = (i + 1) % n;

        twiceArea += points[i].x * points[next].y
                   - points[i].y * points[next].x;
    }

    if (twiceArea < 0) {
        twiceArea = -twiceArea;
    }

    // 정수 좌표로 이루어진 다각형의 넓이는
    // 항상 정수 또는 정수 + 0.5
    cout << twiceArea / 2;
    cout << (twiceArea % 2 == 0 ? ".0" : ".5") << '\n';

    return 0;
}
