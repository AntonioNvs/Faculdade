#include <iostream>

using namespace std;

int main() {
  int N, L, H;

  cin >> N >> L >> H;

  int marked[N], values[N];

  for(int i = 0 ; i < N; i++) cin >> values[i];
  for(int i = 0 ; i < N; i++) cin >> marked[i];

  int maxi = values[0], curr = values[0];
  int mark = marked[0];

  for(int i = 1; i < N; i++) {    
    if(curr + values[i]>  values[i]) {
      curr += values[i];
      mark += marked[i];
    } else {
      curr = values[i];
      mark = marked[i];
    }

    if(mark >= L && mark <= H)
      maxi = max(maxi, curr);
  }

  cout << maxi << endl;

  return 0;
}