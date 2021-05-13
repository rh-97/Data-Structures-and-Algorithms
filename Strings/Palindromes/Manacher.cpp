/*

  Author: Rakibb Hasan
  Manacher's Algorithm for the longest Palindromic Substring.

*/


#include<bits/stdc++.h>
using namespace std;
 
#define speed ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

string longestPalindrome(string &s) {
    int n = s.size(), m = 2*n + 1;

    string str(m, '#');
    for (int i = 0, j = 0; j < m and i < n; ++j) {
        if (j & 1) str[j] = s[i++];
    }

    vector<int> pal_len(m);
    int start = 0, end = 0;
    int l = 0, r = 0, max_len = 0;

    for (int i = 0; i < m; ) {
        while (start > 0 and end < m and str[start - 1] == str[end + 1]) --start, ++end;
        pal_len[i] = end - start + 1;

        if (max_len < pal_len[i])  max_len = pal_len[i], l = start;

        if (end == m - 1) break;

        int center = end + 1;

        for (int j = i + 1; j <= end; ++j) {
            pal_len[j] = min(pal_len[i - (j - i)], 2 * (end - j) + 1);
            if (j + (pal_len[i - (j - i)] >> 1) == end) {
                center = j; break;
            }
        }
        i = center, start = center - (pal_len[i] >> 1), end = center + (pal_len[i] >> 1);
    }

    return s.substr(l >> 1, max_len >> 1);;
    }
void solve() {
    string s = "cccabdadbaccc";
    cout << '\n' << longestPalindrome(s) << '\n';
}
 
int32_t main() {
    speed
    int Q = 1;
//     cin >> Q;
    while (Q--) {
      solve();
    }
    return 0;
}
 
