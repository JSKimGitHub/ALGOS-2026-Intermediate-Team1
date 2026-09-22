#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> A(n), B(n), C(n), D(n);
    for (int i = 0; i < n; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

    vector<int> AB, CD;
    AB.reserve((size_t)n * n);
    CD.reserve((size_t)n * n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    long long count = 0;
    long long i = 0, j = (long long)CD.size() - 1;
    long long sz = AB.size();
    while (i < sz && j >= 0) {
        long long sum = (long long)AB[i] + CD[j];
        if (sum < 0) {
            i++;
        } else if (sum > 0) {
            j--;
        } else {
            int a = AB[i], c = CD[j];
            long long cntA = 0, cntC = 0;
            while (i < sz && AB[i] == a) { cntA++; i++; }
            while (j >= 0 && CD[j] == c) { cntC++; j--; }
            count += cntA * cntC;
        }
    }

    cout << count << '\n';
    return 0;
}
