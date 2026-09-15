#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

// Fast I/O를 위한 빠른 GCD 구현
inline long long gcd(long long a, long long b) {
    while (b) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<pair<long long, long long>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    if (N <= 2) {
        cout << N << "\n";
        return 0;
    }

    int max_points = 0;

    // 해시 맵 재사용으로 메모리 할당 오버헤드 최소화
    unordered_map<long long, int> slope_count;

    for (int i = 0; i < N; ++i) {
        slope_count.clear();
        // N - i가 이미 구한 max_points보다 작거나 같으면 더 이상 탐색 불필요 (가지치기)
        if (N - i <= max_points) break;

        int local_max = 0;

        for (int j = i + 1; j < N; ++j) {
            long long dx = points[j].first - points[i].first;
            long long dy = points[j].second - points[i].second;

            // 약분
            long long g = gcd(abs(dx), abs(dy));
            dx /= g;
            dy /= g;

            // 기울기 방향 정규화 (dx > 0 또는 dx == 0일 때 dy > 0)
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }

            // (dx, dy) 정수 쌍을 64비트 정수 하나로 인코딩
            // dx, dy는 int 범위 내에 들어오므로 32비트씩 할당
            long long key = ((long long)dx << 32) | (unsigned int)dy;

            int count = ++slope_count[key];
            if (count > local_max) {
                local_max = count;
            }
        }

        max_points = max(max_points, local_max + 1);
    }

    cout << max_points << "\n";

    return 0;
}