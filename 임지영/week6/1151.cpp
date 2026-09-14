#include <iostream>
using namespace std;

const int MAXN = 105;
int N;
pair<long long, long long> pts[MAXN];
pair<long long, long long> hull[2 * MAXN];

long long cross(pair<long long,long long> O, pair<long long,long long> A, pair<long long,long long> B) {
    return (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> pts[i].first >> pts[i].second;
    }

    sort(pts, pts + N);

    // Andrew's monotone chain
    int k = 0;
    // 아래쪽 껍질
    for (int i = 0; i < N; i++) {
        while (k >= 2 && cross(hull[k-2], hull[k-1], pts[i]) <= 0) k--;
        hull[k++] = pts[i];
    }
    // 위쪽 껍질
    int lower = k + 1;
    for (int i = N - 2; i >= 0; i--) {
        while (k >= lower && cross(hull[k-2], hull[k-1], pts[i]) <= 0) k--;
        hull[k++] = pts[i];
    }

    k--; // 시작점 중복 제거

    long long sum = 0;
    for (int i = 0; i < k; i++) {
        int j = (i + 1) % k;
        sum += hull[i].first * hull[j].second - hull[j].first * hull[i].second;
    }
    sum = abs(sum);

    double area = sum / 2.0;
    double rounded = round(area * 10) / 10.0;

    if (rounded == (long long)rounded) {
        cout << (long long)rounded << "\n";
    } else {
        printf("%.1f\n", rounded);
    }

    return 0;
}