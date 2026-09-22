#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> A(n), B(n), C(n), D(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    // A+B의 모든 합을 해시맵에 저장 (합 -> 등장 횟수)
    unordered_map<long long, long long> sumAB;
    sumAB.reserve(n * n * 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sumAB[A[i] + B[j]]++;
        }
    }

    // C+D 합을 구해서, -(C+D)가 sumAB에 몇 번 있었는지 누적
    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long need = -(C[i] + D[j]);
            auto it = sumAB.find(need);
            if (it != sumAB.end()) {
                count += it->second;
            }
        }
    }

    cout << count << endl;

    return 0;
}