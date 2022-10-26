#include <bits/stdc++.h>
using namespace std;

int bissexto(int y) {
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

int days_of_month(int m, int y) {
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
            return 31;
        else if(m == 2 && bissexto(y))
            return 29;
        else if(m == 2)
            return 28;
        else
            return 30;
}

int qtd_days(int init[3], int end[3]) {
    int ans = 0;

    if(init[0] == end[0]) {
        if(init[1] == end[1])
            return ans = end[2] - init[2];
        else {
            ans = days_of_month(init[1], init[0]) - init[2]; 
            for(int i = init[1]+1; i < end[1]; i++)
                ans += days_of_month(i, init[0]);
            return ans += end[2];
        }
    }
    
    ans = days_of_month(init[1], init[0]) - init[2];

    for(int i = init[1]+1; i <= 12; i++)
        ans += days_of_month(i, init[0]);

    for(int i = init[0]+1; i < end[0]; i++) {
        if(bissexto(i))
            ans += 366;
        else
            ans += 365;
    }

    for(int i = 1; i < end[1]; i++)
        ans += days_of_month(i, end[0]);
    
    return ans += end[2];
}

int str_to_int(string n) {
    int ans = 0;
    for(int i = 0; i < n.size(); i++)
        ans += pow(10, n.size()-i-1)*((int)n[i]-'0');
    return ans;
}

int main() {
  int N; cin >> N;

  while(N--) {
    string init, end; cin >> init >> end;

    int date1[3], date2[3];

    string k; int c = 0;
    /*
    2014-06-23
    k = "23"
    c = 2
    date1 = {2014, 6, 23}
    */
    for(int i = 0; i < init.size(); i++) {
        if(init[i] == '-') {
            date1[c] = str_to_int(k);
            c++;
            k = "";
        } else {
            k += init[i];
        }
    }
    date1[c] = str_to_int(k);

    k = "";c = 0;
    for(int i = 0; i < end.size(); i++) {
        if(end[i] == '-') {
            date2[c] = str_to_int(k);
            c++;
            k = "";
        } else {
            k += end[i];
        }
    }
    date2[c] = str_to_int(k);

    if(date1[0]*365 + date1[1]*30 + date1[2] > date2[0]*365 + date2[1]*30 + date2[2]) {
        cout << qtd_days(date2, date1) << endl;
    }
     else 
        cout << qtd_days(date1, date2) << endl;
  }

  return 0;
}