#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
vector<long long> subsetSums(const vector<long long>& vals, long long m) {
    int k = vals.size();
    vector<long long> sums(1 << k, 0);
    for (int mask = 1; mask < (1 << k); mask++) {
        int low = __builtin_ctz(mask);
        sums[mask] = (sums[mask & (mask - 1)] + vals[low]) % m;
    }
    return sums;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    long long m;
    cin >> n >> m;
 
    vector<long long> a(n);
    for (auto& x : a) cin >> x;
 
    int h = n / 2;
    vector<long long> left(a.begin(), a.begin() + h);
    vector<long long> right(a.begin() + h, a.end());
 
    vector<long long> L = subsetSums(left, m);
    vector<long long> R = subsetSums(right, m);
    sort(R.begin(), R.end());
 
    long long best = 0;
    long long rMax = R.back();
    for (long long l : L) {
        auto it = lower_bound(R.begin(), R.end(), m - l);
        if (it != R.begin()) best = max(best, l + *(it - 1));
        best = max(best, (l + rMax) % m);
    }
 
    cout << best << '\n';
    return 0;
}
