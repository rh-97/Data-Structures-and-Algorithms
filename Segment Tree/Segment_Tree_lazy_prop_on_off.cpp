
/*

  Author: Rakib Hasan
  Problem link: https://www.spoj.com/problems/LITE/
  The code basically updates and acquires that how many bulb is on in a given range given initially every bulb is off.
  
*/




#include<bits/stdc++.h>
using namespace std;

#define speed ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

#define PB push_back

typedef vector<int> veci;
typedef set<int> seti;
typedef vector<bool> vecb;

#define rep(i, n) for (int i = 0; i < n; ++i)

vector<int> on(262144, 0);
vector<bool> prop(262144, false);

void update(int at, int &l, int &r, int L, int R) {
    if (l > R or L > r) return;
    if (l <= L and R <= r) {
        prop[at] = !prop[at];
        on[at] = (R - L + 1) - on[at];
        return;
    }
    int left = (at << 1), right = left + 1, mid = L + ((R - L) >> 1);
    update(left, l, r, L, mid);
    update(right, l, r, mid + 1, R);
    on[at] = on[left] + on[right];
    if (prop[at]) on[at] = (R - L + 1) - on[at];
}

int query(int at, int &l, int &r, int L, int R, bool carry = false) {
    if (l > R or L > r) return 0;
    if (l <= L and R <= r) {
        if (carry) return (R - L + 1) - on[at];
        return on[at];
    }
    int left = (at << 1), right = left + 1, mid = L + ((R - L) >> 1);
    carry ^= prop[at];
    return query(left, l, r, L, mid, carry) + query(right, l, r, mid + 1, R, carry);
}

void solve() {
	int N, M;
    cin >> N >> M;
    int c, p, q;
    rep(i, M) {
        cin >> c >> p >> q;
        if (c == 1) cout << query(1, p, q, 1, N) << '\n';
        else update(1, p, q, 1, N);
    }
}

int32_t main() {
	speed
	int Q = 1; //cin >> Q;
	while (Q--) {
		solve();
	}
	return 0;
}



