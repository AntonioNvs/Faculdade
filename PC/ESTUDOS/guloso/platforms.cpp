#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, D; cin >> N >> M >> D;

    vector<int> plats(M);
    for(auto &u : plats) cin >> u;
    
    // Soma das plataformas
    int sum = 0;
    for(int i = 0; i < M; i++) sum += plats[i];

    vector<int> print(N+1);

    int crr = 0, k = 0;
    int rest = 9999;
    while(crr < N+1) {
        int rest = N-crr;
        if(rest == 0) break;
        int jump = min(rest-sum+1, D);
        if(sum == 0 && crr+jump <= N) {
            cout << "NO" << endl;
            return 0;
        } else if(sum == 0) break;
        
        int tam = plats[k];

        crr += jump;
        for(int i = 1; i <= jump; i++) print[crr-jump+i] = 0;
        sum -= tam;
        k++;
        while(tam--) {
            print[crr] = k;
            crr++;
        }
        crr--;
    }

    cout << "YES" << endl;
    for(int i = 1; i <= N; i++)
        cout << print[i] << ' ';
    cout << endl;


    return 0;
}