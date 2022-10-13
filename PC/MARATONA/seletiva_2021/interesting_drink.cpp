#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, Q;

  cin >> N;
  int prices[N];

  for(int i = 0; i < N; i++)
    cin >> prices[i];

  sort(prices, prices + N);

  cin >> Q;
  int target;
  while(Q--)
    {
      cin >> target;
      int ans=upper_bound(prices,prices + N, target) - prices;
      cout << ans << endl;
    }
    
  return 0;
}