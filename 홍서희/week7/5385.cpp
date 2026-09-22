#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> subsetSums(const vector<long long>& vals) {
    int k = vals.size();
    vector<long long> sums(1 << k, 0);
    for (int mask = 1; mask < (1 << k); mask++) {
        int low = __builtin_ctz(mask);
        sums[mask] = sums[mask & (mask - 1)] + vals[low];
    }
    return sums;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;

    vector<long long> cards(N);
    for (auto& x : cards) cin >> x;

    int h = N / 2;
    vector<long long> left(cards.begin(), cards.begin() + h);
    vector<long long> right(cards.begin() + h, cards.end());

    vector<long long> L = subsetSums(left);
    vector<long long> R = subsetSums(right);
    sort(L.begin(), L.end());

    long long count = 0;
    for (long long r : R) {
        long long need = M - r;
        count += upper_bound(L.begin(), L.end(), need) - lower_bound(L.begin(), L.end(), need);
    }

    if (M == 0) count--;

    cout << count << '\n';
    return 0;
}
