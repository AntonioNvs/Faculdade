#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int main() { _
  int a, N; cin >> N;

  int sum = 0;
  vector<int> arr;
  for(int i = 0; i < N; i++) {
    cin >> a; arr.push_back(a);
    sum += a;
  }

  if(N == 1) {
    cout << max(0, arr[0]) << endl;
    return 0;
  }

  // Calculando o subarray de soma máxima e de soma mínima
  int mini = INT_MAX, maxi = 0;

  vector<int> kadane_min(N), kadane_max(N);
  kadane_min[0] = kadane_max[0] = arr[0];

  for(int i = 1; i < N; i++) {
    kadane_min[i] = min(kadane_min[i-1] + arr[i], arr[i]);
    kadane_max[i] = max(kadane_max[i-1] + arr[i], arr[i]);

    mini = min(kadane_min[i], mini);
    maxi = max(kadane_max[i], maxi);
  }

  cout <<  max(maxi, sum - mini) << endl;

  return 0;
}