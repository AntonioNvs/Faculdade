#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    
    bool prime = true;
    for(int i = 2; i*i <= n; i++)
        if(n % i == 0)
            prime = false;

    if(prime and n > 1)
        cout << "Tio" << endl;
    else
        cout << "Normal" << endl;
}