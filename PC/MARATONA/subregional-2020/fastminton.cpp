#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  // Posição atual (quem sacou)
  char crr = 'L';
  string commands;
  cin >> commands;

  bool not_print = true;
  int pL = 0, pR = 0, gL = 0, gR = 0;
  for(int i = 0; i < commands.size(); i++) {
    char c = commands[i];

    if(c == 'S') {
      if(crr == 'L') pL++;
      else pR++;
    } else if(c == 'R') {
      if(crr == 'L') {
        pR++;
        crr = 'R';
      } else {
        pL++;
        crr = 'L';
      }
    }

    if((pR >= 5 && pR-pL >= 2) || (pR == 10)) {
      gR++;
      pR = 0;
      pL = 0;
      crr = 'R';
    }
    if((pL >= 5 && pL-pR >= 2) || (pL == 10)) {
      gL++;
      pR = 0;
      pL = 0;
      crr = 'L';
    }

    if(c == 'Q') {
      not_print = false;
      if(gL == 2) cout << gL << " (winner) - " << gR << endl;
      else if(gR == 2) cout << gL << " - " << gR << " (winner)" << endl;
      else {
        if(crr == 'L') cout << gL << " (" << pL << "*) - " << gR << " (" << pR << ")" << endl;
        else cout << gL << " (" << pL << ") - " << gR << " (" << pR << "*)" << endl;
      }
    }    
  }

  if(not_print) cout << '\n';
  return 0;
}