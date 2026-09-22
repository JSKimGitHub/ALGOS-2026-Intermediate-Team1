#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;

    vector<long long> vals(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> vals[i];
    vector<long long> S;
    for (int i = 0; i <= N; i++)
        for (int j = i; j <= N; j++)
            S.push_back(vals[i] + vals[j]);
    sort(S.begin(), S.end());

    long long best = 0;
    for (long long a : S) {
        if (a > M) break;
        long long need = M - a;
        auto it = upper_bound(S.begin(), S.end(), need);
        if (it != S.begin()) best = max(best, a + *(it - 1));
    }

    cout << best << '\n';
    return 0;
}
