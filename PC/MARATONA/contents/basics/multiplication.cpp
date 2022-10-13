#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

vector<int> significate(int n) {
  int sinal = (n >= 0 ? 1 : -1);

  int last, qtd = 0;
  n = abs(n);
  vector<int> digs;
  while(n > 0) {
    last = n % 10;
    n /= 10;
    qtd++;
    digs.push_back(sinal*ceil((double)last*pow(10, qtd-1)));
  }

  return digs;
}

int main() { _
  int T; cin >> T;

  while(T--) {
    int a, b;
    cin >> a >> b;

    vector<int> sa = significate(a);
    vector<int> sb = significate(b);
    int exec = 0;
    for(auto da : sa) {
      
      if(da == 0) {
        exec += sb.size();
        continue;
      }
      for(auto db: sb) {
        exec++;
        if(db == 0) continue;
        
        cout << da << " x " << db;

        if(sa.size()*sb.size() == exec) break;

        cout << " + ";
      }
    }
    cout << endl;
  }
  return 0;
}