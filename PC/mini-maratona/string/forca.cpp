#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(){
    int n = 0;
    cin >> n;
    while(n != -1){
        int e = 0;
        bool c = true;
        string s; cin >> s;
        
        vector<int> w(26, 0);
        
        for (auto i : s){
            int idx = i - 'a';
            w[idx]++;
        }
        string ans; cin >> ans;
        int total = 0;
        for (auto i : ans){
            int idx = i - 'a';
            if(w[i] >= 1)
              total += w[i], w[i] = 0;
            else e++;
        }
        for (auto i : w) if(i >= 1) c = false;
        
        cout << "Jogo " << n << endl;
        if(e < 7 and c) cout << "ganhou." << endl;
        else if( e >= 7) cout << "perdeu." << endl;
        else cout << "desistiu." << endl;
        cin >> n;
    }
    return 0;
}