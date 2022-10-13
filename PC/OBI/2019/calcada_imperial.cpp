#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

#define MAXN 510

using namespace std;

vector<pair<int, int>> pairs;
int have[MAXN], history_pairs[MAXN], sequence[MAXN];
int N;

void get_all_pairs(int curr) {
  if(curr == N)
    return;

  for(int i = curr; i <= N; i++) {
    if(have[i] && i != curr) {
      if(pairs.size() == 0 || (history_pairs[i] != curr && history_pairs[curr] != i)) {
        pairs.push_back(make_pair(i, curr));
        history_pairs[i] = curr;
        history_pairs[curr] = i;
      }
    }
  }

  get_all_pairs(curr+1);
}

int main() {
  memset(have, 0, sizeof(have));
  memset(history_pairs, 0, sizeof(history_pairs));

  cin >> N;

  int tmp;
  for(int i = 0; i < N; i++) {
    cin >> tmp;
    sequence[i] = tmp;
    have[tmp] = 1;
  }

  get_all_pairs(1);

  int maxi = 1;

  for(auto pair : pairs) {
    int qtd = 0;
    int last = -2;

    cout << pair.first << " " << pair.second << endl;

    for(int i = 0; i < N; i++) {
      int curr = sequence[i];

      if(curr == pair.first || pair.second == curr) {
        if(last != i-1) {
          qtd++;
          last = i;
        }
      }
    }
    
    maxi = max(maxi, qtd);
  }

  cout << maxi << endl;

  return 0;
}