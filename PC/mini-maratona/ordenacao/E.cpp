#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int t; cin >> t;
  while(t--) {
    string w; cin >> w;

    int s = w.size();
    vector<int> arr(s);

    for(int i = 0; i < s; i++) arr[i] = (int)w[i];

    int i, key, j, ans = 0;
    for (i = 1; i < s; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            ans++;
        }
        arr[j + 1] = key;
        ans++;
    }

    cout << ans << endl;
  }
  return 0;
}