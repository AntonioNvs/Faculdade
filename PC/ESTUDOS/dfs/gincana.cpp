#include <bits/stdc++.h>

#define MAXN 1010
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int N, M;
int students[MAXN];
vector<int> adj[MAXN];

void dfs(int x, int c) {
  if(students[x] != -1)
    return;

  students[x] = c;
  for(auto w : adj[x])
    dfs(w, c);
}

int main() { _
    memset(students, -1, sizeof(students));

    cin >> N >> M;
    int a, b;

    for(int i = 0; i < M; i++) {
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    int count = 1;
    for(int i = 1; i <= N; i++) {
      dfs(i, count);
      if(students[i] == count)
        count++;
    }
    
    cout << count-1 << endl;

    return 0;
}