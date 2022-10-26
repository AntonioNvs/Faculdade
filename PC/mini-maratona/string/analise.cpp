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

set<string> good({"excelente", "bom", "otimo", "adoro", "amo"}), 
    bad({"ruim", "pessimo", "odeio", "droga", "fraco"});


vector<string> split(string s){
    int last = -1;
    vector<string> ret;
    for(int i=0; i<s.size(); i++){
        if(s[i] < 'a' or s[i] > 'z') {
            ret.pb(s.substr(last+1, i-last-1)); 
            last = i;
        }
    }
    ret.pb(s.substr(last+1, s.size()-last-1)); 
    return ret;
}

int main() { //_
    int n;
    while(cin >> n){
        getchar();
        cout << n << endl;
        int cnt = 0;
        for(int i=0; i<n; i++){
            string s; getline(cin, s);
            vector<string> v = split(s);
            bool inv = 0;
            int pos = 0, neg = 0;
            for(string c : v){
                if(c == "nao") inv = 1;
                if(good.count(c)) {
                    if(inv) neg++, inv = 0;
                    else pos++;
                }
                if(bad.count(c)) {
                    if(inv) pos++, inv = 0;
                    else neg++;
                }
            }
            if(pos > neg) cnt++;
            else if(neg > pos) cnt--;
        }
        if(cnt > 0) cout << "positivo" << endl;
        else if(cnt < 0) cout << "negativo" << endl;
        else cout << "neutro" << endl;
    }
    
    return 0;
}
