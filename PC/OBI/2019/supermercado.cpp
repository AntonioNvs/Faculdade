#include <iostream>
#include <iomanip>
using namespace std;

int main() {    
    int N;
    double price, weight;

    cin >> N;
    cin >> price >> weight;
    
    double greater = weight / price;

    N--;
    while(N--) {
        cin >> price >> weight;
        greater = max(greater, weight / price);
    }
    
    cout << setprecision(2) << fixed;
    cout << 1000 / greater << endl;
}