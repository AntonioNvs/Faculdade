#include <bits/stdc++.h>

#define MAXN 100100
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define ppp pair<pii, pii>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int N, M;

// menor, maior
ppp seg[4*MAXN];
int buckets[MAXN];

ppp build(int p, int l, int r) {
  if(l == r) return seg[p] = {{buckets[l], l}, {buckets[l], l}};
  int m = (l+r)/2;
  
  ppp lr = build(2*p, l, m);
  ppp rr = build(2*p+1, m+1, r);

  if(lr.first.first < rr.first.first)
    seg[p].first = lr.first;
  else
    seg[p].first = rr.first;

  if(lr.second.first > rr.second.first)
    seg[p].second = lr.second;
  else
    seg[p].second = rr.second;

  if(seg[p].first.second == seg[p].second.second) {
    pii mini = seg[p].first;
    pii maxi = seg[p].second;
    if(seg[p].first.second == lr.first.second) {
      if(rr.second.first - mini.first >= maxi.first - rr.first.first)
        maxi = rr.second;
      else 
        mini = rr.first;
    } else {
      if(lr.second.first - mini.first >= maxi.first - lr.first.first)
        maxi = lr.second;
      else 
        mini = lr.first;
    }

    seg[p].first = mini;
    seg[p].second = maxi;
  }

  return seg[p];
}

ppp update(int w, int i, int p, int l, int r) {
  if(i < l || i > r)
    return seg[p];
  if(l == r) {
    seg[p].first.first = min(seg[p].first.first, w);
    seg[p].second.first = max(seg[p].second.first, w);
    return seg[p];
  }

  // UPDATE PART
  int m = (l+r)/2;
  
  ppp lr = update(w, i, 2*p, l, m);
  ppp rr = update(w, i, 2*p+1, m+1, r);

  if(lr.first.first < rr.first.first)
    seg[p].first = lr.first;
  else
    seg[p].first = rr.first;

  if(lr.second.first > rr.second.first)
    seg[p].second = lr.second;
  else
    seg[p].second = rr.second;

  if(seg[p].first.second == seg[p].second.second) {
    pii mini = seg[p].first;
    pii maxi = seg[p].second;
    if(seg[p].first.second == lr.first.second) {
      if(rr.second.first - mini.first >= maxi.first - rr.first.first)
        maxi = rr.second;
      else 
        mini = rr.first;
    } else {
      if(lr.second.first - mini.first >= maxi.first - lr.first.first)
        maxi = lr.second;
      else 
        mini = lr.first;
    }

    seg[p].first = mini;
    seg[p].second = maxi;
  }

  return seg[p];
}

int query(int a, int b, int p, int l, int r) {
  if(b < l || a > r)
    return -INF;
  if(a <= l && b >= r)
    return seg[p].second.first - seg[p].first.first;

  int m = (l+r)/2;
  return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

int main() { _
  cin >> N >> M;

  for(int i = 1; i <= N; i++)
    cin >> buckets[i];

  ppp res = build(1, 1, N);

  int op, a, b;
  while(M--) {
    cin >> op >> a >> b;

    if(op == 1) {
      update(a, b, 1, 1, N);
    } else {
      cout << query(a, b, 1, 1, N) << endl;
    }
  }
  return 0;
}