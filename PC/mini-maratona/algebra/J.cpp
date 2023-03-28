#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define f first
#define s second

using namespace std;
typedef long long int ll;

int str_to_int(string w) {
  int n = 0;
  for(int i = 0; i < w.size(); i++)
    n += pow(10, w.size()-i-1)*(int)(w[i]-'0');

  return n;
}

bool compare(pii a, pii b) {
  return a.f < b.f;
}

int main() { _
  string p1, p2;
  getline(cin, p1);
  getline(cin, p2);

  int p1c1, p1c2, p1e1, p1e2;

  int k = 0;
  string w;
  for(int i = 0; i < p1.size(); i++) {
    if(p1[i] == '+') {
      w.clear();
      continue;
    }

    if(p1[i] == ' ' && !w.size()) continue;

    if(p1[i] == 'x' || p1[i] == ' ') {
      int o = str_to_int(w);
      w = "";
      if(k == 0) p1c1 = o;
      if(k == 1) p1e1 = o;
      if(k == 2) p1c2 = o;
      k++;
    } else w += p1[i];
  }
  p1e2 = str_to_int(w);

  int p2c1, p2c2, p2e1, p2e2;

  k = 0;
  w;
  for(int i = 0; i < p2.size(); i++) {
    if(p2[i] == '+') {
      w.clear();
      continue;
    }

    if(p2[i] == ' ' && !w.size()) continue;

    if(p2[i] == 'x' || p2[i] == ' ') {
      int o = str_to_int(w);
      w = "";
      if(k == 0) p2c1 = o;
      if(k == 1) p2e1 = o;
      if(k == 2) p2c2 = o;
      k++;
    } else w += p2[i];
  }

  p2e2 = str_to_int(w);

  int pfc1 = p1c1*p2c1;
  int pfe1 = p1e1+p2e1;
  int pfc2 = p1c1*p2c2;
  int pfe2 = p1e1+p2e2;
  int pfc3 = p1c2*p2c1;
  int pfe3 = p1e2+p2e1;
  int pfc4 = p1c2*p2c2;
  int pfe4 = p1e2+p2e2;


  vector<pii> exps = {{pfe1, pfc1}, {pfe2, pfc2}, {pfe3, pfc3}, {pfe4, pfc4}};
  vector<pii> res;

  for(int i = 1; i < 4; i++) {
    int coef = exps[i-1].s;
    bool entry = false;
    int crr = i;
    while(crr < 4 && exps[crr-1].f == exps[crr].f) crr++, coef += exps[crr].s, entry = true;

    if(entry) crr--;
    
    res.pb({exps[i-1].f, coef});
    
    i = crr;
  }

  sort(res.begin(), res.end(), compare);

  for(int i = 0; i < res.size()-1; i++) {
    cout << res[i].s << 'x' << res[i].f << " + ";
  }

  cout << res[res.size()-1].s << 'x' << res[res.size()-1].f << endl;

  return 0;
}