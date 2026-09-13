#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct Point { long long x, y; };

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<Point> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].x >> pts[i].y;
    }
    
    if (n <= 2) { 
        cout << n << "\n"; 
        return 0; 
    }
    
    int max_pts = 0;
    for (int i = 0; i < n; ++i) {
        vector<pair<long long, long long>> slopes;
        // 기준점 i 이후의 점들만 검사하여 중복 연산 방지
        for (int j = i + 1; j < n; ++j) {
            long long dx = pts[j].x - pts[i].x;
            long long dy = pts[j].y - pts[i].y;
            
            if (dx == 0) { dy = 1; }
            else if (dy == 0) { dx = 1; }
            else {
                long long g = gcd(abs(dx), abs(dy));
                dx /= g; dy /= g;
                // 방향 통일 (음수 부호는 dx에 몰아주기)
                if (dx < 0) { dx = -dx; dy = -dy; }
            }
            slopes.push_back({dx, dy});
        }
        sort(slopes.begin(), slopes.end());
        
        int current_max = 0;
        int count = 1;
        for (size_t k = 1; k < slopes.size(); ++k) {
            if (slopes[k] == slopes[k-1]) {
                count++;
            } else {
                current_max = max(current_max, count);
                count = 1;
            }
        }
        if (!slopes.empty()) current_max = max(current_max, count);
        
        // 본인(i)을 포함하여 개수 산정
        max_pts = max(max_pts, current_max + 1);
    }
    
    cout << max_pts << "\n";
    return 0;
}
