#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> A(n), B(n), C(n), D(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    int sz = n * n;
    vector<int> AB(sz), CD(sz);

    int idx = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            AB[idx] = A[i] + B[j];
            CD[idx] = C[i] + D[j];
            idx++;
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    int left = 0;
    int right = sz - 1;
    long long ans = 0;

    while (left < sz && right >= 0) {
        int sum = AB[left] + CD[right];

        if (sum == 0) {
            int val_left = AB[left];
            int val_right = CD[right];
            long long cnt_left = 0;
            long long cnt_right = 0;

            // AB에서 같은 값 개수 세기
            while (left < sz && AB[left] == val_left) {
                cnt_left++;
                left++;
            }
            // CD에서 같은 값 개수 세기
            while (right >= 0 && CD[right] == val_right) {
                cnt_right++;
                right--;
            }

            ans += cnt_left * cnt_right;
        } else if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }

    cout << ans << "\n";
    return 0;
}
