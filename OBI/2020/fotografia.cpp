#include <iostream>
#include <utility>

using namespace std;

int main() {
  int A, L, N, w, h;
  cin >> A >> L >> N;

  int best = -1;
  int best_area = 10e8;

  for(int i = 1; i <= N; i++) {
    cin >> w >> h;

    if((w >= A && h >= L) || (w >= L && h >= A))
      if(w*h < best_area) {
        best = i;
        best_area = w*h;
      }
      
  }

  cout << best << endl;

  return 0;
}