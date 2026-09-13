#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<pair<long long, long long>> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].first >> pts[i].second;
    }
    
    long long area2 = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n; // 마지막 점은 첫 점과 연결
        area2 += pts[i].first * pts[j].second - pts[j].first * pts[i].second;
    }
    
    area2 = abs(area2);
    
    cout << fixed << setprecision(1) << (double)area2 / 2.0 << "\n";
    
    return 0;
}
