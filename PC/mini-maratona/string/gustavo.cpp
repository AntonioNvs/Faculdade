#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; getline(cin, s);
        s.erase(0, 1);
        cout << s << endl;
        for(int i=n%s.size(); i<s.size(); i++) cout << s[i];
        for(int i=0; i<n%s.size(); i++) cout << s[i];
        cout << endl;
    }
    
    return 0;
}