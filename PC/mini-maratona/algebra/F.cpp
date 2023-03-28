#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF= 0x3f3f3f3f3f3fll;

int main() { _
    vector<int> a(4), b(4);
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    b = a;
    a[0] *= 7*7;
    a[1] *= 7;
    a[3] /= 7;

    int max = -1, index;
    for (int i = 0; i < 4; i++){
        if(max < a[i])index=i, max = a[i];
        if(max == a[i] and b[index] < b[i]) index = i;

    }
    if(index == 0) cout << "Hamster ";
    else if(index == 1) cout << "Cachorro ";
    else if(index == 2) cout << "Humano ";
    else cout << "Elfo ";
    cout << "eh o mais velho." << endl; 
    return 0;
}