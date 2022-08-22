#include <iostream>
#include <utility>
#include <vector>
#include <cstring>

#define MAXN 210

using namespace std;

vector<int> adj[MAXN];
int heights[MAXN];
int memory[MAXN];

int dp(int node) {
  if(memory[node] != -1)
    return memory[node];

  int maxi = 0;
  for(int i = 0; i < adj[node].size(); i++)
    maxi = max(maxi, dp(adj[node][i]));

  memory[node] = 1 + maxi;
  return memory[node];
}

int main() {
  int S, T, P;

  cin >> S >> T >> P;

  memset(memory, -1, sizeof(memory));

  for(int i = 1; i <= S; i++)
    cin >> heights[i];

  int out, inp;
  for(int i = 1; i <=T; i++) {
    cin >> out >> inp;
    if (heights[out] > heights[inp])
      adj[out].push_back(inp);
    else if (heights[out] < heights[inp])
      adj[inp].push_back(out);
  }

  cout << dp(P) - 1 << endl;
  return 0;
}