#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    int mx = 0;                                   
    for (int i = 0; i < n - 1; i++) mx = max(mx, p[i]);
    int k = p[n - 1];
    while (k > 0) {
        if (k <= mx) { cout << s.substr(0, k) << "\n"; return 0; }
        k = p[k - 1];
    }
    cout << "Just a legend\n";
}
