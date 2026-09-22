#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<long long> makeSums(
    const vector<long long>& a, int begin, int end, long long m
) {
    vector<long long> sums = {0}; // 아무것도 고르지 않은 경우

    for (int i = begin; i < end; i++) {
        int size = sums.size();

        for (int j = 0; j < size; j++) {
            sums.push_back((sums[j] + a[i]) % m);
        }
    }

    return sums;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long m;
    cin >> n >> m;

    vector<long long> a(n);
    for (auto& x : a) {
        cin >> x;
    }

    int mid = n / 2;
    vector<long long> left = makeSums(a, 0, mid, m);
    vector<long long> right = makeSums(a, mid, n, m);

    sort(right.begin(), right.end());

    long long answer = 0;

    for (long long x : left) {
        // x + y < m인 y 중 최댓값
        auto it = lower_bound(right.begin(), right.end(), m - x);

        if (it != right.begin()) {
            --it;
            answer = max(answer, x + *it);
        }

        // x + y >= m인 경우에는 가장 큰 y가 가장 유리하다.
        answer = max(answer, (x + right.back()) % m);

        if (answer == m - 1) break; // 가능한 최댓값
    }

    cout << answer << '\n';
    return 0;
}
