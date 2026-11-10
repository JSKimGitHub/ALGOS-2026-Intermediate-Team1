#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, w; cin >> n >> w;
    vector<long long> a(n), b(w);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    if (w == 1) { cout << n << "\n"; return 0; }

    vector<long long> s;                          
    for (int i = 1; i < w; i++) s.push_back(b[i] - b[i - 1]);
    s.push_back(LLONG_MAX);
    for (int i = 1; i < n; i++) s.push_back(a[i] - a[i - 1]);

    int m = s.size(), cnt = 0;
    vector<int> p(m, 0);
    for (int i = 1; i < m; i++) {
        int j = p[i - 1];
        while (j && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) j++;
        p[i] = j;
        if (j == w - 1) cnt++;
    }
    cout << cnt << "\n";
}
