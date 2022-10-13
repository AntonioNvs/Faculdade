#include <bits/stdc++.h>

#define MAXN 100100
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int seg[4*MAXN];
int ap[MAXN];

int build(int p, int l, int r) {
  if(l == r)
    return seg[p] = ap[l];
  
  int m = (l+r)/2;

  return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
}

int query(int a, int b, int p, int l, int r) {
  if(b < l || a > r)
    return 0;

  if(l >= a && r <= b)
    return seg[p];

  int m = (l+r)/2;
  return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
}

int update(int v, int i, int p, int l, int r) {
  if(l == r && l == i) {
    return seg[p] = v;
  }

  if(i < l || i > r)
    return seg[p];

  int m = (l+r)/2;
  return seg[p] = update(v, i, 2*p, l, m) + update(v, i, 2*p+1, m+1, r);
}

int main() { _
  int N, Q;
  cin >> N >> Q;

  for(int i = 1; i <= N; i++)
    cin >> ap[i];

  build(1, 1, N);

  int op, K, P;
  while(Q--) {
    cin >> op >> K;
    if(op == 0) {
      cin >> P;
      update(P, K, 1, 1, N);
    } else {
      cout << query(1, K, 1, 1, N) << endl;;
    }
  }

  return 0;
}