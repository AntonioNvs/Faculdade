#include <bits/stdc++.h>

#define MAXN 100100
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

// frequencia, numero
pii seg[4*MAXN];

pii update(int i, int f, int p, int l, int r) {
  if(i < l || i > r) return seg[p];
  if(l == r) {
    int v = seg[p].second;
    return seg[p] = {1, (v + f) % 9};
  }
  int m = (l+r)/2;
  pii lr = update(i, f, 2*p, l, m);
  pii rr = update(i, f, 2*p + 1, l, m);

  if(lr.second == rr.second)
    return seg[p] = {lr.first + rr.first, rr.second};
  else if(lr.first > rr.first)
    return seg[p] = lr;
  else if(true) {

  }
}

pii query(int a, int b, int p, int l, int r) {
  if(b < l || a > r) return {-1, -1};
  if(a <= l && r <= b) return seg[p];

  int m = (l+r)/2;
  pii lr = query(a, b, 2*p, l, m);
  pii rr = query(a, b, 2*p+1, m+1, r);

  if(lr.first > rr.first)
    return lr;
  else if(lr.first < rr.first)
    return rr;
  else if(lr.first == rr.first && lr.second > rr.second)
    return lr;
  else
    return rr;
}

int main() { _
  int N, Q;
  cin >> N >> Q;

  for(int i = 0; i < N; i++)
    seg[i] = {1, 1};

  int a, b;
  while(Q--) {
    cin >> a >> b;
  }
  return 0;
}