#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long M;
    cin >> N >> M;

    vector<long long> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    int n1 = N / 2;
    int n2 = N - n1;

    // 앞쪽 절반 모든 부분집합 합 (공집합 포함)
    vector<long long> A;
    A.reserve(1LL << n1);
    for (int mask = 0; mask < (1 << n1); mask++) {
        long long sum = 0;
        for (int i = 0; i < n1; i++) {
            if (mask & (1 << i)) sum += arr[i];
        }
        A.push_back(sum);
    }

    // 뒤쪽 절반 모든 부분집합 합 (공집합 포함)
    vector<long long> B;
    B.reserve(1LL << n2);
    for (int mask = 0; mask < (1 << n2); mask++) {
        long long sum = 0;
        for (int i = 0; i < n2; i++) {
            if (mask & (1 << i)) sum += arr[n1 + i];
        }
        B.push_back(sum);
    }

    sort(B.begin(), B.end());

    long long count = 0;
    for (long long a : A) {
        long long need = M - a;
        auto range = equal_range(B.begin(), B.end(), need);
        count += (range.second - range.first);
    }

    // A와 B 둘 다 공집합인 경우(합 0+0=0)는 "1장 이상" 조건 위반이므로 M==0일 때 제외
    if (M == 0) count -= 1;

    cout << count << endl;

    return 0;
}