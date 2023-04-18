#include <bits/stdc++.h>

using namespace std;

int main() {
    string S, M; cin >> S;
    map<char, char> cry;

    int p = 0;        

    for(auto c : S) {
        if(cry.find(c) == cry.end())
            cry[c] = (char)('a' + p++);
        M += cry[c];
    }

    cout << M << endl;

    return 0;
}