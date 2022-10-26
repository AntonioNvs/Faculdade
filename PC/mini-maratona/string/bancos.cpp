#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long int ll;

int str_to_int(string n) {
    int ans = 0;
    for(int i = 0; i < n.size(); i++)
        ans += pow(10, n.size()-i-1)*((int)n[i]-'0');
    return ans;
}

int main() { _
  string line;
  while(getline(cin, line)) {
    vector<int> codes;
    string k = "";
    int i;
    for(i = 0; line[i] != ','; i++) {
        if(line[i] == ' ') {
            codes.push_back(str_to_int(k));
            k = "";
        } else {
            k += line[i];
        }
    }
    codes.push_back(str_to_int(k));
    int day = (int)line[i+1]-'0';
    int sun = (line[i+3] == 'T' ? 1 : 0);

    int temp = str_to_int(line.substr(i+5, 2));

    if(day == 2) {
      for(i = 0; i < codes.size(); i++)
        codes[i] = codes[i] + 3;  
    } else {
      for(i = 0; i < codes.size(); i++)
        codes[i] = codes[i] - 3;
    }

    if(!sun || (sun && temp > 30)) {
      for(i = 0; i < codes.size(); i++)
        codes[i] = floor(codes[i]/2);
    }
    

    for(i = 0; i < codes.size(); i++)
      cout << (char)(codes[i]);
    cout << endl;
  }
}