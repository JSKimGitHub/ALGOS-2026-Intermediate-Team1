#include <iostream>
using namespace std;

const int MAXN = 10005;
long long X[MAXN], Y[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        sum += X[i] * Y[j] - X[j] * Y[i];
    }
    sum = abs(sum);

    double area = sum / 2.0;
    printf("%.1f\n", area);

    return 0;
}