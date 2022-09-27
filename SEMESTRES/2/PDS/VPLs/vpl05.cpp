#include <iostream>
#include <vector>

using namespace std;

int main() {
    int l1, l2, c2, el;

    cin >> l1 >> l2 >> c2;

    vector<vector<int>> m1;
    vector<vector<int>> m2;

    for(int i = 0; i < l1; i++) {
        vector<int> row;
        for(int j = 0; j < l2; j++) {
            cin >> el;
            row.push_back(el);
        }
        m1.push_back(row);
    }

    for(int i = 0; i < l2; i++) {
        vector<int> row;
        for(int j = 0; j < c2; j++) {
            cin >> el;
            row.push_back(el);
        }
        m2.push_back(row);
    }

    vector<vector<int>> m3(l1, vector<int>(c2));


    for(int i = 0; i < l1; i++)
        for(int j = 0; j < c2; j++)
            for(int k = 0; k < l2; k++)
                m3[i][j] += m1[i][k] * m2[k][j];

    for(int i = 0; i < l1; i++) {
        for(int j = 0; j < c2; j++)
            cout << m3[i][j] << " ";
        cout << endl;
    }
        
    return 0;
}