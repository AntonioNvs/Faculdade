#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  int arr[N];
  cin >> arr[0];

  long long int ans = 0;
  for(int i = 1; i < N; i++) {
    cin >> arr[i];
    if(arr[i] - arr[i-1] < 0)
      ans += arr[i] - arr[i-1];
  }

  cout << abs(ans) << endl;

  return 0;
}