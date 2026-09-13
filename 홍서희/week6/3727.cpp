#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return abs(a);
}

struct Point {
    long long x, y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    if (n <= 2) {
        cout << n << "\n";
        return 0;
    }

    int max_points = 2;

    vector<pair<long long, long long>> slopes;
    slopes.reserve(n);

    for (int i = 0; i < n; i++) {
        slopes.clear();

        for (int j = i + 1; j < n; j++) {
            long long dx = points[j].x - points[i].x;
            long long dy = points[j].y - points[i].y;

            if (dx == 0) {
                dy = 1; 
            } else {
                long long g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }
            }
            slopes.push_back({dy, dx});
        }
        
        sort(slopes.begin(), slopes.end());

        int local_max = 0;
        int current_count = 0;
        
        for (size_t k = 0; k < slopes.size(); k++) {
            if (k == 0 || slopes[k] == slopes[k - 1]) {
                current_count++;
            } else {
                local_max = max(local_max, current_count);
                current_count = 1;
            }
        }
        local_max = max(local_max, current_count);
        
        max_points = max(max_points, local_max + 1);
    }

    cout << max_points << "\n";

    return 0;
}
