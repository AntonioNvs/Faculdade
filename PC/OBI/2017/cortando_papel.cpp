#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define MAXN 100100

using namespace std;

int main() {
    int N, h;
    int states[MAXN];

    cin >> N;

    vector<pair<int, int>> papers;

    for(int i = 1; i <= N; i++) {
        cin >> h;
        states[i] = 1;
        papers.push_back(make_pair(h, i));
    }
    
    sort(papers.begin(), papers.end());

    int greater = 1, tires = 1;

    for(int i = 0; i < papers.size(); i++) {
        int pos = papers[i].second;
        states[pos] = 0;

        if(states[pos-1] == 1 &&  states[pos+1] == 1)
            tires++;
        if(states[pos+1] == 0 && states[pos+1] == 0)
            tires--;

        if(i == N-1 || papers[i].first != papers[i+1].first)
            greater = max(greater, tires);
    }

    cout << greater + 1 << endl;

    return 0;
}