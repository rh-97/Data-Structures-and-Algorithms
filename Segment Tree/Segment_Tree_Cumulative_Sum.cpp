/*

  Author: Rakib Hasan
  Problem Link: https://www.spoj.com/problems/LITE/
  Returns the sum of values within a specific range of an array.
  
*/


#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define speed ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
 
#define PB push_back
 
typedef vector<int> veci;
typedef set<int> seti;
typedef vector<bool> vecb;
 
#define rep(i, n) for (int i = 0; i < n; ++i)
 
struct Node {
    int sum = 0;
    int prop = 0;
};
vector<Node> A(262144);
void add(int at, int l, int r, int L, int R, int v) {
    if (r < L or l > R) return;
    if (l <= L and R <= r) {
        A[at].sum += (R - L + 1) * v;
        A[at].prop += v;
        return;
    }
    int mid = L + ((R - L) >> 1);
    int left = at * 2;
    int right = left + 1;
    add(left, l, r, L, mid, v);
    add(right, l, r, mid + 1, R, v);
    A[at].sum = A[left].sum + A[right].sum + A[at].prop * (R - L + 1);
}
int query(int at, int l, int r, int L, int R, int carry = 0) {
    if (r < L or l > R) return 0;
    if (l <= L and R <= r) return A[at].sum + (R - L + 1) * carry;
    int mid = L + ((R - L) >> 1);
    int left = (at << 1);
    int right = left + 1;
    carry += A[at].prop;
    return query(left, l, r, L, mid, carry) + query(right, l, r, mid + 1, R, carry);
}
void solve() {
	int N, C;
    cin >> N >> C;
    int c, p, q, v;
    A.clear(); A.resize(262144);
    for (int i = 0; i < C; ++i) {
        cin >> c;
        if (c == 0) {
            cin >> p >> q >> v;
            add(1, p, q, 1, N, v);
        } else {
            cin >> p >> q;
            cout << query(1, p, q, 1, N, 0) << '\n';
        }
    }
}
 
int32_t main() {
	speed
	int Q = 1; cin >> Q;
	while (Q--) {
		solve();
	}
	return 0;
}
 

