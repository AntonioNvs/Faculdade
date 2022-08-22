#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, v;
  vector<int> weights;

  cin >> N;

  for(int i = 1; i <= N; i++) {
    cin >> v;
    weights.push_back(v);
  }

  sort(weights.begin(), weights.end());

  if(weights[0] > 8) {
    cout << 'N' << endl;
    return 0;
  }

  for(int i = 1; i < N; i++)
    if(weights[i] - weights[i-1] > 8) {
      cout << 'N' << endl;
      return 0;
    }

  cout << 'S' << endl;
  return 0;
}