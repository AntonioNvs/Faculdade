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
    ll A, B, C; cin >> A >> B >> C;
    char o; cin >> o;

    if(o == 'A') {
        ll aux1 = (C/2)*5 + (C%2) + (B/2)*3 + (B%2);
        ll aux2 = (((C/3)*5 + B)/2)*3 + (((C/3)*5 + B) % 2);
        ll aux3 = (((B/5)*3+C)/2)*5 + (((B/5)*3+C) % 2);
        cout << max(aux1, max(aux2, aux3)) + A << endl;        
    } else if(o == 'B') {
        ll aux1 = (A/3)*2 + (A%3) + (C/3)*5 + (C%3);
        ll aux2 = (((A/5)*2 + C)/3)*5 + (((A/5)*2 + C) % 3); 
        ll aux3 = (((C/2)*5 + A)/3)*2 + (((C/2)*5 + A) % 3);

        cout << max(aux1, max(aux2, aux3)) + B << endl;        
    } else {
        ll aux1 = (A/5)*2 + (A%5) + (B/5)*3 + (B%5);
        ll aux2 = (((A/3)*2 + B)/5)*3 + (((A/3)*2 + B) % 5);
        ll aux3 = (((B/2)*3 + A)/5)*2 + (((B/2)*3 + A) % 5);
        
        cout << max(aux1, max(aux2, aux3)) + C << endl;        
    }

    return 0;
}