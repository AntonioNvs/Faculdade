#include <bits/stdc++.h>

#define MAXN 100100
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int v[MAXN];
int seg[4*MAXN];

int build(int p, int l, int r) {
    if(l == r) 
        return seg[p] = v[l];

    int m = (l+r)/2;

    return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
}

int query(int a, int b, int p, int l, int r) {
    if(b < l or r < a)
        return INF;
    if(a <= l and r <= b)
        return seg[p];

    int m = (l + r)/2;

    return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));    
}

int update(int i, int x, int p, int l, int r) {
    if(i < l or r < i) return seg[p];
    if(l == r) return seg[p] = x;

    int m = (l+r)/2;
    return seg[p] = min(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
}

int main() {
    _

    // Falta implementar a main. 

    return 0;
}