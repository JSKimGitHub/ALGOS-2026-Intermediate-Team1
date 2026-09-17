#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getSubsetSums(const vector<long long>& arr, vector<long long>& sums) {
    int sz = arr.size();
    for (int mask = 0; mask < (1 << sz); ++mask) {
        long long sum = 0;
        for (int i = 0; i < sz; ++i) {
            if (mask & (1 << i)) sum += arr[i];
        }
        sums.push_back(sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int mid = n / 2;
    vector<long long> left_arr(a.begin(), a.begin() + mid);
    vector<long long> right_arr(a.begin() + mid, a.end());

    vector<long long> left_sums, right_sums;
    getSubsetSums(left_arr, left_sums);
    getSubsetSums(right_arr, right_sums);

    sort(right_sums.begin(), right_sums.end());

    long long ans = 0;
    for (long long s : left_sums) {
        long long need = m - s;
        auto range = equal_range(right_sums.begin(), right_sums.end(), need);
        ans += (range.second - range.first);
    }

    if (m == 0) ans--;

    cout << ans << "\n";
    return 0;
}
