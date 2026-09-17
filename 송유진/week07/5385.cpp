#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    long long total_sum = 1LL * n * (n + 1) / 2;
    if (total_sum % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    long long target = total_sum / 2;
    vector<long long> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = target; j >= i; --j) {
            dp[j] += dp[j - i];
        }
    }

    cout << dp[target] / 2 << "\n";
    return 0;
}
