#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> A(n), B(n), C(n), D(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    vector<int> AB, CD;
    AB.reserve(n * n);
    CD.reserve(n * n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    int left = 0;
    int right = static_cast<int>(CD.size()) - 1;
    long long answer = 0;

    while (left < static_cast<int>(AB.size()) && right >= 0) {
        int sum = AB[left] + CD[right];

        if (sum < 0) {
            left++;
        } else if (sum > 0) {
            right--;
        } else {
            // 같은 합이 여러 번 나올 수 있으므로 각각의 개수를 센다.
            int abValue = AB[left];
            int cdValue = CD[right];
            long long abCount = 0;
            long long cdCount = 0;

            while (left < static_cast<int>(AB.size()) &&
                   AB[left] == abValue) {
                abCount++;
                left++;
            }

            while (right >= 0 && CD[right] == cdValue) {
                cdCount++;
                right--;
            }

            answer += abCount * cdCount;
        }
    }

    cout << answer << '\n';
    return 0;
}
