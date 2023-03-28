#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF= 0x3f3f3f3f3f3fll;

bool bi(int n){
    if(n%400 == 0) return true;
    if(n%4 ==0 and n%100 !=0) return true;
    return false;
}

int main() { _
    int y;
    while(cin >> y){
        float price = float(y);
        int count = 0;
        
        int a = y;
        if(a%20 == 0) count++;
        if(bi(y)) count++;
        else if(a%10 == 0) count++;

        int d = 0;
        if(a%20 == 0) d+=20;
        if(bi(y)) d += 5;
        else if(a%10 == 0) d+=10;
        
        if(count != 0)d /= count;
        price -= y*d/100;
        cout <<price<<endl;
    }

    return 0;
}