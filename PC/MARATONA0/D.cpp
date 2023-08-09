#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define pb push_back
#define f first
#define s second

using namespace std;

int main() {
    long long int x; cin >> x;
    cout << x << endl;
    while(x >= 10) {
        long long int l = x % 10;
        x -= l;
        x /= 10;


        x = x*3 + l;
        cout << x << endl;
    }
    return 0;
}
