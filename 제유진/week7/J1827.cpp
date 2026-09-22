#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> score(N + 1);
    score[0] = 0; // 다트를 던지지 않는 경우

    for (int i = 1; i <= N; i++) {
        cin >> score[i];
    }

    // 다트 2발 이하로 만들 수 있는 모든 합
    vector<int> sums;
    sums.reserve((N + 1) * (N + 1));

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            sums.push_back(score[i] + score[j]);
        }
    }

    sort(sums.begin(), sums.end());

    // 두 개의 2발 이하 합을 더해 M 이하인 최댓값 찾기
    int left = 0;
    int right = static_cast<int>(sums.size()) - 1;
    int answer = 0;

    while (left <= right) {
        int total = sums[left] + sums[right];

        if (total <= M) {
            answer = max(answer, total);
            left++;  // 합을 더 키워 본다
        } else {
            right--; // 합을 줄인다
        }
    }

    cout << answer << '\n';
    return 0;
}
