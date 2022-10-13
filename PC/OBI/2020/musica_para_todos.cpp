#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> preferences;
vector<pair<int, int>> history;

int changes = 0;

void song(int music) {
  for(int i = 0; i < preferences.size(); i++) {
    if(preferences[i].second == music) {
      if(history.size() > 0) {
        if(history[0].first == i && history[0].second == music) {
          changes = -1;
          return;
        }
      }

      history.push_back(make_pair(i, music));
      changes++;

      song(preferences[i].first);
      break;
    }
  }
}

int main() {
  int N, M, C, A, D;

  cin >> N >> M >> C;
  
  for(int i = 0; i < N; i++) {
    cin >> A >> D;
    preferences.push_back(make_pair(A, D));
  }
  
  song(C);

  cout << changes << endl;

}