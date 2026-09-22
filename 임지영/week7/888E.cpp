#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int n1 = n / 2;
    int n2 = n - n1;

    // 왼쪽 절반: 모든 부분집합 합 (mod m)
    vector<long long> left;
    left.reserve(1 << n1);
    for (int mask = 0; mask < (1 << n1); mask++) {
        long long sum = 0;
        for (int i = 0; i < n1; i++) {
            if (mask & (1 << i)) sum += a[i];
        }
        left.push_back(sum % m);
    }

    // 오른쪽 절반: 모든 부분집합 합 (mod m)
    vector<long long> right;
    right.reserve(1 << n2);
    for (int mask = 0; mask < (1 << n2); mask++) {
        long long sum = 0;
        for (int i = 0; i < n2; i++) {
            if (mask & (1 << i)) sum += a[n1 + i];
        }
        right.push_back(sum % m);
    }

    sort(right.begin(), right.end());
    long long maxRight = right.back(); // 오른쪽 최댓값 (wrap 케이스용)

    long long best = 0;
    for (long long s1 : left) {
        // 1) s1 + s2 < m 인 범위에서 s2를 최대로 (넘치지 않게)
        long long target = m - 1 - s1;
        auto it = upper_bound(right.begin(), right.end(), target);
        if (it != right.begin()) {
            long long s2 = *(--it);
            best = max(best, s1 + s2);
        }
        // 2) s1 + s2 >= m 로 넘어가는(wrap) 경우도 체크
        best = max(best, (s1 + maxRight) % m);
    }

    cout << best << endl;

    return 0;
}