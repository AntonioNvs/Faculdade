#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define f first
#define s second

using namespace std;
typedef long long int ll;

int main() { _
  string s = "Antônio Néves";

  for (int i = 0; i < s.size(); i++)
    cout << (int)s[i] - 'A' + 65 << endl;

  cout << s << endl;

  return 0; 
}