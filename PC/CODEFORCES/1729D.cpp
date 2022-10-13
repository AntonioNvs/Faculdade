#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, N;

    cin >> T;

    while(T--) {
        cin >> N;

        int x[N], y[N];
        
        for(int i = 0; i < N; i++)
            cin >> x[i];
        
        for(int i = 0; i < N; i++)
            cin >> y[i];

        int diff[N];

        for(int i = 0; i < N; i++)
            diff[i] = y[i] - x[i];

        sort(diff, diff+N);

        int l = 0, r = N-1;
        int qtd = 0;

        while(r > l) {
            if(diff[l] + diff[r] >= 0) {
                qtd++;
                l++;
                r--;
            } else {
                l++;
            }
        }

        cout << qtd << endl;
    }
    return 0;
}