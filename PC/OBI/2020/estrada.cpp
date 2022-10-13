#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  int T, N;

  cin >> T >> N;
  cout << fixed << setprecision(2);

  vector<double> points;
  points.push_back(0.0);

  for(int i = 1; i <= N; i++) {
    double tmp;
    cin >> tmp;
    points.push_back(tmp);
  }  
  points.push_back(T);

  sort(points.begin(), points.end());

  double mini = 10e8;

  for(int i = 1; i < points.size()-1; i++) {
    double neigh;
    if(i == 1)
      neigh = (points[i+1] - points[i]) / 2 + points[i];
    else if(i == points.size()-1)
      neigh = (points[i] - points[i-1])/2 + (T - points[i]);
    else
      neigh = (points[i] - points[i-1])/2 + (points[i+1] - points[i])/2;

    mini = min(mini, neigh);
  } 

  cout << mini << endl;
  
  return 0;
}