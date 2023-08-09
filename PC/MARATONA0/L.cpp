#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define pb push_back
#define f first
#define s second

using namespace std;

int main() {
    int N, M, S; cin >> N >> M >> S;
    long long int av = 0;

    int x, y, r;
    while(S--) {
        cin >> x >> y >> r;

        int width = (x-max(x-r,1)) + (min(x+r, N)-x) + 1;
        int height = (x-max(y-r, 1)) + (min(y+r, M)-x) + 1;

        av += width*height;
    }

    cout << (int)(av/(N*M)) << endl;

    return 0;
}
