#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    string res; cin >> res;
    for (int t = 1; t < n; t++) {
        string w; cin >> w;
        int L = min(w.size(), res.size());
        string s = w + "#" + res.substr(res.size() - L);   
        int m = s.size();
        vector<int> p(m, 0);
        for (int i = 1; i < m; i++) {
            int j = p[i - 1];
            while (j && s[i] != s[j]) j = p[j - 1];
            if (s[i] == s[j]) j++;
            p[i] = j;
        }
        res += w.substr(p[m - 1]);
    }
    cout << res << "\n";
}
