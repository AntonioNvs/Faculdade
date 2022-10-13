#include <bits/stdc++.h>

using namespace std;

double string_to_int(string s) {
    double res = 0;
    for(int i = 0; i < s.size(); i++)
        res += ((int)(s[i]-'0'))*pow(10, s.size()-i);
    
    return res;
}

double transform(string s) {
    string f;
    string d;
    bool change = false;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == '.') change = true;
        else if(change) d += s[i];
        else f += s[i];
    }

    return string_to_int(f) + string_to_int(d)/100;
}

int main() {
    int N;
    cin >> N;

    double total = 0.0;
    
    N++;
    string input;
    int ans = 0;
    bool first = true;
    while(N--) {
        cin >> input;
        total += transform(input);

        if(first) {
            first = false;
            continue;
        }

        if(total != (int)total)
            ans++;
    }

    cout << ans << endl;
}