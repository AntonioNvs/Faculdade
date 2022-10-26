#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int N;
  int i = 1;
  while(1) {
    cin >> N;
    if(!N) break;

    int t;
    for(int j = 1; j <= N; j++) {
      cin >> t;
      if(t == j) {
        cout << "Teste " << i << endl; 
        cout << j << endl;
      }
    }

    i++;
  }
  return 0;
}