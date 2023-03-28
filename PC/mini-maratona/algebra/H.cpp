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
  double M, J, C;

  cin >> M >> J >> C;

  int k = 0;
  double sum = 0.0; 
  while(sum < C) {
    sum += M;
    sum *= (1 + (J)/100);
    k++;
  }
  int year = k/12;
  int month = k%12;
  if(year == 0) {
    cout << month << " mes(es)" << endl;
  } else {
    cout << k/12 << " ano(s)";
    if(month != 0) {
      cout << " e " << month << " mes(es)" << endl;
    }
  }

  return 0;
}