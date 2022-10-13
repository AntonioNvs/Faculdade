#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int N;
  cin >> N;

  int tab[11][11];
  memset(tab, 0, sizeof(tab));

  int D, L, R, C;

  int pos = true;
  while(N--) {
    cin >> D >> L >> R >> C;
    if(D == 0) {
      for(int i = 0; i < L; i++) {
        if(i+C > 10 || tab[R][C+i] >= 1) pos = false;
        else tab[R][C+i]++;
      }
    } else {
      for(int i = 0; i < L; i++) {
        if(i+L > 10 || tab[R+i][C] >= 1) pos = false;
        else tab[R+i][C]++;
      }
    }
  }

  if(pos) {
    cout << 'Y' << endl;
  } else {
    cout << 'N' << endl;
  }
  return 0;
}