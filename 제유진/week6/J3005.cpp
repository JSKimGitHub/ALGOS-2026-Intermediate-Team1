#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct Point {
    long long x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> p(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;

        sum += p[i].x * p[j].y
             - p[i].y * p[j].x;
    }

    long long area2 = abs(sum);

    // area2는 실제 넓이의 2배
    cout << area2 / 2;
    cout << (area2 % 2 == 0 ? ".0" : ".5") << '\n';

    return 0;
}
