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
    vector<long long> occ(n + 1, 0);              
    for (int i = 0; i < n; i++) occ[p[i]]++;
    for (int i = n - 1; i > 0; i--) occ[p[i - 1]] += occ[i];
    for (int i = 0; i <= n; i++) occ[i]++;

    vector<int> lens;
    for (int k = n; k > 0; k = p[k - 1]) lens.push_back(k);
    reverse(lens.begin(), lens.end());

    cout << lens.size() << "\n";
    for (int len : lens) cout << len << " " << occ[len] << "\n";
}
