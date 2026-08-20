#include <iostream>
using namespace std;
#include <algorithm>
#include <stack>
#include <vector>

class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    int n = position.size();
    double time;
    stack<double> st;
    vector<pair<int, int>> cars;
    for (int i = 0; i < n; i++)
      cars.push_back({position[i], speed[i]});

    /*sort(cars.begin(), cars.end(), [](pair<int, int> &a, pair<int, int> &b) {
      return a.first > b.first;
    });*/

    sort(cars.begin(), cars.end());

    for (int i = n - 1; i >= 0; i--) {
      time = ((double)target - cars[i].first) / cars[i].second;
      if (st.empty() || time > st.top()) {
        st.push(time);
      }
    }

    return st.size();
  }
};

int main() {
  int target, n;
  cout << "enter target: ";
  cin >> target;
  cout << "enter size of vector: ";
  cin >> n;
  vector<int> position(n);
  vector<int> speed(n);
  cout << "enter positions: ";
  for (int i = 0; i < n; i++)
    cin >> position[i];
  cout << "enter speeds: ";
  for (int i = 0; i < n; i++)
    cin >> speed[i];
  Solution *sol = new Solution();
  int carFleet = (*sol).carFleet(target, position, speed);
  cout << "car fleet: " << carFleet;
}
