#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

int main() {
    int N;
    cin >> N;
    
    vector<Point> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y;
    }
    
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        int next = (i + 1) % N;
        sum += (p[i].x * p[next].y) - (p[next].x * p[i].y);
    }
    
    double area = abs(sum) / 2.0;
    cout << fixed;
    cout << setprecision(1);
    cout << area << "\n";
    
    return 0;
}
