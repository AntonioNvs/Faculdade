#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define pb push_back
#define f first
#define s second

typedef long long ll;

using namespace std;

int main() {
    int gr, pd, geo; cin >> gr >> pd >> geo;
    char o; cin >> o;

    if(o == 'A') {
        gr += (3*pd) / 2;
        gr += (5*geo) / 2;

        cout << max(gr, pd + geo) << endl;
    } else if(o == 'B') {
        pd += (5*geo)/3;
        pd += (2*gr)/3;

        cout << max(pd, gr + geo) << endl;
    } else {
        geo += (2*gr)/5;
        geo += (3*pd)/5;

        cout << max(geo, gr + pd) << endl;
    }
    return 0;
}