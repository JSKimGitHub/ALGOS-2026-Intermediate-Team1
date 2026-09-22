#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    int total = N * (N + 1) / 2;

    // 전체 합이 홀수면 두 부분수열의 합이 같을 수 없다.
    if (total % 2 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    // N은 첫 번째 부분수열에 고정한다.
    int target = total / 2 - N;

    if (target < 0) {
        cout << 0 << '\n';
        return 0;
    }

    // dp[s] = 1부터 현재 숫자까지 사용해 합 s를 만드는 방법의 수
    vector<long long> dp(target + 1, 0);
    dp[0] = 1;

    for (int num = 1; num < N; num++) {
        // 같은 숫자를 여러 번 사용하지 않도록 뒤에서부터 갱신
        for (int sum = target; sum >= num; sum--) {
            dp[sum] += dp[sum - num];
        }
    }

    cout << dp[target] << '\n';
    return 0;
}
