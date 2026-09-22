#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> subsetSums(const vector<int>& vals) {
    int k = vals.size();
    vector<long long> sums(1 << k, 0);
    for (int mask = 1; mask < (1 << k); mask++) {
        int low = __builtin_ctz(mask);
        sums[mask] = sums[mask & (mask - 1)] + vals[low];
    }
    return sums;
}

int main() {
    int N;
    cin >> N;

    long long S = (long long)N * (N + 1) / 2;
    if (S % 2 != 0) {
        cout << 0 << '\n';
        return 0;
    }
    long long target = S / 2;

    int h = N / 2;
    vector<int> left, right;
    for (int i = 1; i <= h; i++) left.push_back(i);
    for (int i = h + 1; i <= N; i++) right.push_back(i);

    vector<long long> L = subsetSums(left);
    vector<long long> R = subsetSums(right);
    sort(L.begin(), L.end());

    long long count = 0;
    for (long long r : R) {
        long long need = target - r;
        count += upper_bound(L.begin(), L.end(), need) - lower_bound(L.begin(), L.end(), need);
    }

    cout << count / 2 << '\n';
    return 0;
}
