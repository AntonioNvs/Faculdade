#include <bits/stdc++.h>

using namespace std;

bool sorting(pair<int, int> a, pair<int, int> b) {
  if(a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

int main() {
  int N;
  string type;

  cin >> N;

  pair<int, int> order[N];
  string names[N];

  for(int i = 0; i < N; i++) {
    cin >> names[i] >> type;

    if(type == "rat")
      order[i] = make_pair(0, i);
    else if(type == "woman" || type == "child")
      order[i] = make_pair(1, i);
    else if(type == "man")
      order[i] = make_pair(2, i);
    else
      order[i] = make_pair(3, i);
  }

  sort(order, order + N, sorting);

  for(int i = 0; i < N; i++)
    cout << names[order[i].second] << endl;
}