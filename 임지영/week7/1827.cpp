#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long M;
    cin >> N >> M;

    vector<long long> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];

    // 0발, 1발, 2발로 만들 수 있는 모든 합 (같은 영역 중복 선택 허용)
    vector<long long> S;
    S.reserve(1 + N + (long long)N * (N + 1) / 2);

    S.push_back(0);                    // 0발
    for (int i = 0; i < N; i++)        // 1발
        S.push_back(P[i]);
    for (int i = 0; i < N; i++)        // 2발 (i==j면 같은 영역 두 번)
        for (int j = i; j < N; j++)
            S.push_back(P[i] + P[j]);

    sort(S.begin(), S.end());

    long long best = 0;
    // S에서 두 개(각각 0~2발)를 뽑아 합이 M 이하가 되는 최댓값 찾기
    for (long long a : S) {
        if (a > M) break; // 정렬돼있으니 이후로는 더 커짐
        long long need = M - a;
        // need 이하인 가장 큰 값 찾기
        auto it = upper_bound(S.begin(), S.end(), need);
        if (it != S.begin()) {
            --it;
            best = max(best, a + *it);
        }
    }

    cout << best << endl;

    return 0;
}