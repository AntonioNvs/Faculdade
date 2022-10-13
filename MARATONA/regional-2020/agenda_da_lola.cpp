#include <bits/stdc++.h>

#define MAXX 300100

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    int ativs[MAXX];
    memset(ativs, 0, sizeof(ativs));

    int s, d;
    int maxi = -1;
    while(N--) {
        cin >> s >> d;

        for(int i = s; i <= s+d; i++) ativs[i] = 1;
        maxi = max(maxi, s+d);

    }

    int conflits = 101010101;
    int time = 0;
    
    for(int i = 0; i <= 480; i++) {
        int aux = i;
        int c = 0;

        while(aux <= maxi) {
            if(ativs[aux]) c++;
            aux += X;
        }

        if(c < conflits) {
            time = i;
            conflits = c;
        }
    }

    cout << time << ' ' << conflits << endl;

    return 0;
}