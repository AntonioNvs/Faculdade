#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define pb push_back
#define f first
#define s second

using namespace std;

int main() {
    string s; cin >> s;

    int a = 0, b = 0;

    for(int i = 0; i < 3; i++) {
        if(s[i] == 'X') a++;
        else  b++;
    }

    if(a <= 1 || a == 3) cout << "?" << endl;
    
    else {
        if(s[0] == 'X' && s[1] == 'X')
            cout << "Alice" << endl;
        else if(s[1] == 'X' && s[2] == 'X')
            cout << "Alice" << endl;
        else
            cout << '*' << endl;
    }


    return 0;
}
