#include <bits/stdc++.h>

using namespace std;

string reverseStr(string str)
{
    int n = str.length();

    for (int i = 0; i < n / 2; i++)
      swap(str[i], str[n - i - 1]);
    
    return str;
}

string int_to_str(int num) {
  string res = "";
  while(num > 0) {
    res += (num%10) + '0';
    num /= 10;
  }

  return reverseStr(res);
}

string transform(string num) {
  int idx = 0;
  for(int i = num.size(); i >= 0; i--) {
    if((int)num[i] - '0' >= 5) {
      idx = i;
      break;
    }
  }

  if(num[idx] - '0' >= 5) {
    if(idx == 0)
      num = int_to_str((num[0]-'0')*2) + num.substr(1, num.size());
    else {
      string f = num.substr(0, idx);
      num = f + int_to_str((num[idx]-'0')*2) + num.substr(idx+1, num.size());
    }
  } else
    num[0] = (char)(int)(num[0]-'0')*2 + '0';
  
  return num;
}

int main() {
  int T, N, M;
  cin >> T;

  while(T--) {
    cin >> N >> M;
    string num = int_to_str(N);

    for(int k = 0; k < M; k++)
      num = transform(num);
    cout << num << endl;
  }
  return 0;
}