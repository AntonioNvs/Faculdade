#include <bits/stdc++.h>

using namespace std;

int main() {
    map<char, char> cripto;

    string s, p;
    cin >> s >> p;

    for(int i = 0; i < 26; i++)
        cripto[s[i]] = (char)((int)'a' + i);

    for(int i = 0; i < p.size(); i++)
        p[i] = cripto[p[i]];

    cout << p << endl;
}