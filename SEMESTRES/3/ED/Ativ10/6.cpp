#include <iostream>

using namespace std;

int square(int N) {
    int i = N/2;
    while(true) {
        if(i*i <= N && (i+1)*(i+1) > N)
            break;
        else if(i*i > N)
            i /= 2;
        else
            i += i/2 + 1;        
    }

    return i;
}

int main() {
    int N;
    cin >> N;
    cout << square(N) << endl;
    return 0;
}