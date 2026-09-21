#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long S = (long long)N * (N + 1) / 2;

    // 홀수면 절반으로 나눌 수 없음
    if (S % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    long long target = S / 2;

    int n1 = N / 2;      // 앞쪽 절반
    int n2 = N - n1;     // 뒤쪽 절반

    // 앞쪽 절반 모든 부분집합 합
    vector<long long> A;
    A.reserve(1LL << n1);
    for (int mask = 0; mask < (1 << n1); mask++) {
        long long sum = 0;
        for (int i = 0; i < n1; i++) {
            if (mask & (1 << i)) sum += (i + 1); // 1..n1
        }
        A.push_back(sum);
    }

    // 뒤쪽 절반 모든 부분집합 합
    vector<long long> B;
    B.reserve(1LL << n2);
    for (int mask = 0; mask < (1 << n2); mask++) {
        long long sum = 0;
        for (int i = 0; i < n2; i++) {
            if (mask & (1 << i)) sum += (n1 + i + 1); // n1+1..N
        }
        B.push_back(sum);
    }

    sort(B.begin(), B.end());

    long long count = 0;
    for (long long a : A) {
        long long need = target - a;
        if (need < 0) continue;
        auto range = equal_range(B.begin(), B.end(), need);
        count += (range.second - range.first);
    }

    // 부분집합 하나 = 여집합 하나가 동일한 분할을 두 번 세는 것이므로 절반
    long long answer = count / 2;

    cout << answer << endl;

    return 0;
}