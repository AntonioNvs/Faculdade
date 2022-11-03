#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;

    while(T--) {
        string w; cin >> w;

        int l = -1, maxi = -1;
        for(int i = 0; i < w.size(); i++)
            if(w[i] == 'R') 
                maxi = max(i - l, maxi), l = i;

        maxi = max((int)w.size() - l, maxi);

        cout << (maxi != INT_MAX ? maxi : w.size()+1) << endl;
    }

    return 0;
}