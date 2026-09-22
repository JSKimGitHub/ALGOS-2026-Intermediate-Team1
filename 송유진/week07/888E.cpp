#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getModSums(const vector<long long>& arr, long long m, vector<long long>& sums) {
    int sz = arr.size();
    for (int mask = 0; mask < (1 << sz); ++mask) {
        long long s = 0;
        for (int i = 0; i < sz; ++i) {
            if (mask & (1 << i)) s = (s + arr[i]) % m;
        }
        sums.push_back(s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
    }

    int mid = n / 2;
    vector<long long> left_arr(a.begin(), a.begin() + mid);
    vector<long long> right_arr(a.begin() + mid, a.end());

    vector<long long> left_sums, right_sums;
    getModSums(left_arr, m, left_sums);
    getModSums(right_arr, m, right_sums);

    sort(right_sums.begin(), right_sums.end());
    right_sums.erase(unique(right_sums.begin(), right_sums.end()), right_sums.end());

    long long ans = 0;
    for (long long x : left_sums) {
        // 경우 1: x + y < m
        auto it = lower_bound(right_sums.begin(), right_sums.end(), m - x);
        if (it != right_sums.begin()) {
            --it;
            ans = max(ans, x + *it);
        }
        ans = max(ans, (x + right_sums.back()) % m);
    }

    cout << ans << "\n";
    return 0;
}
