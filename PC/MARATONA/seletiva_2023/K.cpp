#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;

    priority_queue<int, vector<int>, greater<int>> arr;

    int ans = 0;
    bool changed = false;
    N *= 2;
    while(N--) {
        string op; int v; cin >> op;
        if(op == "add") {
            cin >> v;

            if(!arr.empty())
                if(v > arr.top())
                    changed = true;
            arr.push(v);
        } else {
            if(changed) ans++;
            arr.pop();
            changed = false;
        }
    }

    cout << ans << endl;

    return 0;
}