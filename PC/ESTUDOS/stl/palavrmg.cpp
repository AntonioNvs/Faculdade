#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int p; cin >> p;

  while(p--) {
    string a, b, c;
    cin >> a;
    
    c = a;
    
    for(int i = 0; i < a.size(); i++) a[i] = tolower(a[i]);

    b = a;
    sort(a.begin(), a.end());

    set<char> cars;
    for(auto c : a) cars.insert(c);

    cout << c << ": " << ((a == b && cars.size() == a.size()) ? 'O' : 'N') << endl; 
  }
  return 0;
}