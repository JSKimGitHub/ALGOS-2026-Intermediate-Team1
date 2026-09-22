#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> p(n + 1, 0); 
    for (int i = 1; i <= n; ++i) cin >> p[i];

    // 2발 던져서 만들 수 있는 모든 점수 합
    vector<long long> two_darts;
    two_darts.reserve((n + 1) * (n + 1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (p[i] + p[j] <= m) {
                two_darts.push_back(p[i] + p[j]);
            }
        }
    }

    sort(two_darts.begin(), two_darts.end());
    two_darts.erase(unique(two_darts.begin(), two_darts.end()), two_darts.end());

    long long max_score = 0;
    for (long long first_two : two_darts) {
        long long remain = m - first_two;
        auto it = upper_bound(two_darts.begin(), two_darts.end(), remain);
        if (it != two_darts.begin()) {
            --it;
            max_score = max(max_score, first_two + *it);
        }
    }

    cout << max_score << "\n";
    return 0;
}
