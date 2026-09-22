#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<long long> makeSums(const vector<long long>& cards, int start, int end) {
    vector<long long> sums = {0}; // 아무 카드도 뽑지 않은 경우

    for (int i = start; i < end; i++) {
        int size = sums.size();

        for (int j = 0; j < size; j++) {
            sums.push_back(sums[j] + cards[i]);
        }
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
    for (auto& card : cards) {
        cin >> card;
    }

    int mid = N / 2;
    vector<long long> left = makeSums(cards, 0, mid);
    vector<long long> right = makeSums(cards, mid, N);

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    long long answer = 0;
    int i = 0;
    int j = static_cast<int>(right.size()) - 1;

    while (i < static_cast<int>(left.size()) && j >= 0) {
        long long sum = left[i] + right[j];

        if (sum < M) {
            i++;
        } else if (sum > M) {
            j--;
        } else {
            long long leftValue = left[i];
            long long rightValue = right[j];
            long long leftCount = 0;
            long long rightCount = 0;

            while (i < static_cast<int>(left.size()) && left[i] == leftValue) {
                leftCount++;
                i++;
            }

            while (j >= 0 && right[j] == rightValue) {
                rightCount++;
                j--;
            }

            answer += leftCount * rightCount;
        }
    }

    // M이 0이면 양쪽에서 아무 카드도 뽑지 않은 경우가 포함된다.
    if (M == 0) {
        answer--;
    }

    cout << answer << '\n';
    return 0;
}
